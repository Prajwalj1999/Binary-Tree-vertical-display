#include<iostream>
#include<stdlib.h>
#include<string>
#include<queue>
using namespace std;

class node
{
    public:

    int value;
    node *left,*right;

    node()
    {
        value=0;
        left=right=NULL;
    }
    void input(int v)
    {
            value = v;
    }
    void output()
    {
        cout<<value;
    }
};

class tree
{

    public:

    node *root;

    tree()
    {
        root=NULL;
    }
    void insert_tree()
    {
        int v,i=0;
        string path="";
        node *current=root,*newnode=NULL;
        cout<<"\nEnter the value to enter:";
        cin>>v;
        cin.get();

        if(root==NULL)
        {
            root=new node();
            if(root==NULL)
            {
                cout<<"No Memory";
                exit(0);
            }
            root->input(v);
            return;
        }
        cout<<"\nEnter the path(l/r):";
        getline(cin,path);
        while(path[i])
        {

            if(path[i]=='l')
            {
                if(current->left==NULL)
                {
                    newnode=new node();
                    newnode->input(v);
                    current->left=newnode;
                    return;
                }
                else
                {
                    current=current->left;
                }
            }//if(path[i]=='l')
            else//if(path[i]=='r')
            {
                if(current->right==NULL)
                {
                    newnode=new node();
                    newnode->input(v);
                    current->right=newnode;
                    return;
                }
                else
                {
                    current=current->right;
                }
            }

            i++;
        }


    }//insert_tree

    void delete_tree(node *n)
    {

        if(n==NULL)
            return;
        delete_tree(n->left);
        delete_tree(n->right);
        delete n;
    }

    void display()
    {
        int len=0,level=1,previous_level=0;
        node *cur=root;
        queue <node *> node_queue;
        queue <int> level_queue;

        node_queue.push(cur);
        level_queue.push(level);

        bool level_change=false;

        while( len = node_queue.size() )
        {
            bool null_full=true;
            for(int i=1;i<=len;i++)
            {
                node *temp = node_queue.front();
                node_queue.pop();
                if(temp)
                    null_full=false;
                node_queue.push(temp);
            }
            if(null_full==true)
                break;

            cur = node_queue.front();
            level = level_queue.front();
            node_queue.pop();
            level_queue.pop();

            if(cur)
            {
                node_queue.push(cur->left);
                level_queue.push(level+1);
                node_queue.push(cur->right);
                level_queue.push(level+1);
            }

            if(previous_level!=level)
            {
                previous_level=level;
                cout<<"\n";
                for(int i=0;i<40-previous_level;i++)  cout<<" ";
            }
            if(cur)
                cout<< (cur->value) <<" ";
            else
                cout<<"  ";

        }
    }

};

int main()
{
    tree T;
    int n;
    cout<<"\nEnter the number of values:";
    cin>>n;
    cin.get();

    for(int nodes=0;nodes<n;nodes++)
    {
        T.insert_tree();
    }

    cout<<"\n";
    T.display();

    T.delete_tree(T.root);
    return 0;
}
