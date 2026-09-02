
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* next=curr->next;
        if(next==NULL)return {-1,-1};
        int k=2;
        vector<int> pos;
        while(next!=NULL){
            if(curr->val>prev->val && curr->val>next->val){
                pos.push_back(k);
            }
            else if(curr->val<prev->val && curr->val<next->val){
                pos.push_back(k);
            }
            prev=prev->next;
            curr=curr->next;
            next=next->next;
            k++;
        }
        if(pos.size()==0)return {-1,-1};
        int mini=INT_MAX;
        int maxi=pos[pos.size()-1]-pos[0];
        for(int i=0;i<pos.size()-1;i++){
            mini=min(mini,pos[i+1]-pos[i]);
        }
        if(mini==INT_MAX||maxi==INT_MIN)return {-1,-1};
        return {mini,maxi};
    }
};