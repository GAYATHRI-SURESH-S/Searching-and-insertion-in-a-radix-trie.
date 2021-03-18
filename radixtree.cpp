#include<bits/stdc++.h>
using namespace std;
const int alpha=26;
struct trie{
     struct trie *children[alpha];
     bool isend;
};
struct trie *getnode()
{
  struct trie *temp=new trie;
  temp->isend=false;
for(int i=0;i<alpha;i++)
{
   temp->children[i]=NULL;
}
return temp;
}
void insert(struct trie *root,string s)
{
  struct trie *temp=root;
  for(int i=0;i<s.length();i++)
  {
      int index=s[i]-'a';
      if(!temp->children[index])
           temp->children[index]=getnode();
      temp = temp->children[index];
}
temp->isend=true;
bool trie_search(struct trie *root,string s)
{
  struct trie*temp=root;
  for(int i=0;i<s.length();i++)
  {
     int index=s[i]-'a';
     if(!temp->children[index])
          return false;
     temp = temp->children[index];
}
if(temp!=NULL && temp->isend)
    return true;
return false;
}
int main()
{
 string s[]={"burger","burglar","joyful"};
 int n=sizeof(s)/sizeof(s[0]);
 struct trie*root=getnode();
 for(int i=0;i<n;i++)
    insert(root,s[i]);
 trie_search(root,"burger")?cout<<"yes":cout<<"no";
return 0;
}
