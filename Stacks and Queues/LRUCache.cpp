// Implementation of Least Recently Used cache using Doubly Linked List and a map 
// LC - 146 

class LRUCache {
public:
    // Defining the structure of a doubly linked list which stores cache 
    struct Node{
        Node* next ;
        Node* prev ;
        int key ;
        int value ;

        Node(int key1,int value1){
            key = key1 ;
            value = value1;
            next = nullptr ;
            prev = nullptr ;
        }
    };
    
    // deifing the data memebers of LRUCache
    Node* head = new Node(-1,-1) ;
    Node* tail = new Node(-1,-1) ;
    unordered_map<int,Node*> mpp ;
    int cap ;

    // constructor of LRUCache 
    LRUCache(int capacity) {
        cap = capacity ;
        head->next = tail ;
        tail->prev = head ;
    }
    

    // Extract the value of the key from the cache memory if present in it 
    int get(int key) {
        // Check if the key is present in the map 
        if(mpp.find(key) != mpp.end()){
            // Get the referance of the node stored in the map 
            Node* temp = mpp[key] ;
            int val = temp->value ;
            // Move the node back to start of the LL first we free the node and   the add it in the start of the LL
            deleteNode(temp) ;
            addNode(temp) ;
            return val ;
        }
        // Return -1 if not present in it 
        return -1 ;
    }
    
    // Adds the key val if not present in the map if present then updated the value 
    void put(int key, int value) {
        // If the key is not present in the map and capacity is there 
        if(mpp.find(key) == mpp.end() && cap != 0){
            Node* newNode = new Node(key , value );
            addNode(newNode) ;
            mpp[key] = newNode ;
            cap-- ;
        }
        // If the key is not present in the map and the capacity is full
        else if(mpp.find(key) == mpp.end() && cap == 0){
            Node* newNode = new Node(key , value) ;
            Node* temp = tail->prev ;
            mpp.erase(temp->key) ;
            deleteNode(temp) ;
            addNode(newNode) ;
            mpp[key] = newNode ;
        }
        // If the key is present in the map then just update it 
        else{
            Node* temp = mpp[key]  ;
            temp->value = value ;
            deleteNode(temp);
            addNode(temp) ;
        }
    }

    // Adds the given node at the start of the LL
    void addNode(Node* newNode){
        Node* temp = head->next ;
        head->next = newNode ;
        newNode->next = temp ;
        newNode->prev = head ;
        temp->prev = newNode ;
    }

    // Deletes the given node from he LL 
    void deleteNode(Node* delNode){
        Node* temp1 = delNode->prev ;
        Node* temp2 = delNode->next ;
        temp1->next = temp2 ;
        temp2->prev = temp1 ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */