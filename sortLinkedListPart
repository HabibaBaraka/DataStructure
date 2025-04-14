/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 /* full reverse 
  node pre= null ,
  node cur= head ,
  while cur :
  node next =cur.next ,
  
  cur.next =pre ,
  pre= cur,
  cur=next
  and so on...

 */
 /* approch get start node and startnode -1,
 normal reverse r-l+1 time 
 node start-1 pointer to last 
 node start pointer to last+1

 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        int times=r-l+1;
        if(times==1||!head||!head->next)return head;
if(l==1){
    ListNode* pre=nullptr,*start=head,*cur=start;


while(times--){
    ListNode*next=cur->next;
    cur->next=pre;
    pre=cur;
    cur=next;
}

// start pointer to cur

start->next=cur;
head=pre;
   return head;
}




     int cnt=1;
     ListNode* Bstart=head;
     while(cnt!=l-1){
            Bstart=Bstart->next;
            cnt++;
     }
ListNode* pre=nullptr,*start=Bstart->next,*cur=start;


while(times--){
    ListNode*next=cur->next;
    cur->next=pre;
    pre=cur;
    cur=next;
}
//Bstart pointer to pre 
// start pointer to cur
Bstart->next=pre;
start->next=cur;
   return head; }
};
