template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* newNode = new Node(elem); 
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* x = head;
        while (x->next != nullptr) {
            x = x->next;
        }
        x->next = newNode;
    }
    this->length++;  
}


template <typename T>
void LinkedList<T>::clear() {
    // TODO
    // Node* x = head;
    // while (x->next != nullptr){
    //     x->next = head;
    //     delete x;
    //     x = head;
    // }
    Node* prev;
    while(head != nullptr){
        prev = head;
        head = head->next;
        delete prev;

    }
    this->length = 0; 
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    // TODO
    if (position < 0 || position >= this->length) {
        throw std::out_of_range("position out of bounds");
    }

    Node* x = head;
    for (int i = 0; i < position; i++){
        x = x->next;
    }
        return x->value;


}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    // TODO
    if (position < 0 || position >= this->length) {
        throw std::out_of_range("position out of bounds");
    }

    Node* x = head;
    for (int i = 0; i < position; i++){
       x = x->next;
    }
    x->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
