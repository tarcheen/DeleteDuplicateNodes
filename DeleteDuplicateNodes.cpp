/*
Developer: Hamed Mirlohi
Date: 11/27/2019
In this program, duplicate nodes are deleted using hash function
*/

#include <iostream>
#include <map>

struct node
{
    node* next;
    int data;
}*ptr;

void display_node(const node* head)
{
    while(head != nullptr)
    {
        std::cout<< "Node: "<< head << ": " <<head->data << std::endl;
        head = head->next;
    }
}

// adding nodes to the end of the list
node* build_LLL(node* head, int d)
{
    // case there is no node
    if(head == nullptr)
    {
        head = new node;
        head->data = d;
    }
    
    else
    {
        node* tmp = head;
        // lets get to the last node
        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        // pointing to last node now
        tmp->next = new node;
        tmp->next->data = d;
    }
    return head;
}


node* erase_duplicates(node* head)
{
    // if no node, just return
    if(head == nullptr)
        return nullptr;
    
    // if there is single node, no duplicates
    if(head->next == nullptr)
    {
        return head;
    }
    
    std::map<int, int> hash; 
    
    node* ptr = head->next;
    node* chaser = head;

    // insert first node into hash
    hash[chaser->data] = chaser->data;
    
    while(ptr != nullptr)
    {
        // data exist, remove where ptr is pointing(remove duplicate)
        if(hash.find(ptr->data) != hash.end())
        {
            // procedure to remove an element in the linear link list
            node* tmp = ptr->next;
            delete ptr;
            ptr = tmp;
            chaser->next = ptr;
        }
        else
        {
            // node doesnt exist in hash table, add the node to the hash 
            hash[ptr->data] = ptr->data;
            // traverse both pointers to adjacent node
            ptr = ptr->next;
            chaser = chaser->next;
        }
    }
    return head;
}

int main(void)
{
      node* h = nullptr;
      

      std::cout<<"-----------Before----------"<<std::endl;


      h = build_LLL(h, 1);
      h = build_LLL(h, 2);
      h = build_LLL(h, 2);
      h = build_LLL(h, 4);
      h = build_LLL(h, 1);
      h = build_LLL(h, 6);
    
      display_node(h);
    
      std::cout<<"---------- After-----------"<<std::endl;
    
      h = erase_duplicates(h);
    
      display_node(h);
      
}

