// Least Frequecy Used Cache Implementation 
// LC - 460 


// The structure of a node with an additional cnt 
struct Node {
    int key;
    int value;
    int cnt;
    Node* next;
    Node* prev;

    Node(int key1, int value1) {
        key = key1;
        value = value1;
        cnt = 1;
        next = nullptr;
        prev = nullptr;
    }
};

// The structure of a List that is a collection of a node of a specific cnt 
struct List {
    int size;
    Node* head;
    Node* tail;

    List() {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }

    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

class LFUCache {
public:
    int cap;
    int minFreq;
    int curSize;

    unordered_map<int, Node*> KeyNode;
    unordered_map<int, List*> FreqListmpp;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
        curSize = 0;
    }

    // Updates the freq of the given node and updates it to the new higher freq list 
    void updateFreq(Node* node) {
        KeyNode.erase(node->key);
        FreqListmpp[node->cnt]->deleteNode(node);

        // If the count of the current node is the min freq and it is the only element in that FreqList map then increase the minFreq 
        if (node->cnt == minFreq && FreqListmpp[node->cnt]->size == 0) {
            minFreq++;
        }

        node->cnt += 1;
        // If no List of the current freq is there then create a new list 
        if (FreqListmpp.find(node->cnt) == FreqListmpp.end()) {
            FreqListmpp[node->cnt] = new List();
        }
        // Then directly add it in the particular freq list 
        FreqListmpp[node->cnt]->addNode(node);
        KeyNode[node->key] = node;
    }

    // The get function returns the value if the key is present in the cache 
    int get(int key) {
        if (KeyNode.find(key) != KeyNode.end()) {
            Node* node = KeyNode[key];
            updateFreq(node);
            return node->value;
        }
        return -1;
    }

    // Adds or updates the cache for the given key value pair 
    void put(int key, int value) {
        if (cap == 0) return;
        // If the element is present then just update the value and increase the freq 
        if (KeyNode.find(key) != KeyNode.end()) {
            Node* node = KeyNode[key];
            node->value = value;
            updateFreq(node);
        } 
        // if the size is full then remove the least freq one and then add new Node 
        else {
            if (curSize == cap) {
                List* list = FreqListmpp[minFreq];
                Node* nodeToDelete = list->tail->prev;
                KeyNode.erase(nodeToDelete->key);
                list->deleteNode(nodeToDelete);
                curSize--;
            }

            Node* newNode = new Node(key, value);
            minFreq = 1;
            if (FreqListmpp.find(minFreq) == FreqListmpp.end()) {
                FreqListmpp[minFreq] = new List();
            }

            FreqListmpp[minFreq]->addNode(newNode);
            KeyNode[key] = newNode;
            curSize++;
        }
    }
};