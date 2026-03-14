class MyLinkedList {
public:
    struct Node{
        int val;
        Node* next;
        Node(int x){
            val = x;
            next = NULL;
        }
    };
    Node* head;
    int size;
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    int get(int index) {
        if(index >= size) return -1;
        Node* temp = head;
        for(int i=0;i<index;i++){
            temp = temp->next;
        }   
        return temp->val;
    }
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }
    void addAtTail(int val) {
        Node* node = new Node(val);
        if(head == NULL){
            head = node;
        } 
        else{
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = node;
        }   
        size++;
    }
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index == 0){
            addAtHead(val);
            return;
        }
        Node* temp = head;
        for(int i=0;i<index-1;i++){
            temp = temp->next;
        }
        Node* node = new Node(val);
        node->next = temp->next;
        temp->next = node;   
        size++;
    }
    void deleteAtIndex(int index) {
        if(index >= size) return;
        if(index == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else{
            Node* temp = head;
            for(int i=0;i<index-1;i++){
                temp = temp->next;
            }   
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }   
        size--;
    }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */