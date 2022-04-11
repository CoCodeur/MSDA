#ifndef LINKEDLIST_H
    #define LINKEDLIST_H

    #pragma region Structure
    /**
     * @brief Strcture that represent a node in a linkedlist with the next node and the value.
     *
     */
        struct NODE {
            struct NODE* prev;
            struct NODE* next;
            int value;
    };

    /**
     * @brief Structure that represent a doubly linkedlist 
     * 
     */
        struct LINKEDLIST {
            struct NODE* head;
            struct NODE* tail;
            int size;
    };

    #pragma endregion Structure

    #pragma region Methods
    /**
     * @brief Function that intialize new linkedlist
     * @return LINKEDLIST : the linkedlist created
     */
    static struct NODE * linkedlist__new_node(int value);

    /**
     * @brief Function that intialize new linkedlist
     * @return LINKEDLIST : the linkedlist created
     */
    struct LINKEDLIST * linkedlist__new_linkedlist();


    /**
     * @brief Display all nodes in linkedlist on console
     * @param *linkedlist : LINKEDLIST address of linkedlist memory
     */
    void linkedlist__display(struct LINKEDLIST *linkedlist);


    /**
     * @brief Function that return if linkedlist is empty
     * @param *linkedlist : LINKEDLIST address of linkedlist memory
     * @return integer : 1 is True (empty), 0 False (non empty)
     */
    int linkedlist__is_empty(struct LINKEDLIST * linkedlist);

    /**
     * @brief Insert new element in linkedlist by head
     * @param *linkedlist : LINKEDLIST address of linkedlist memory
     * @param value : integer that represent the value of new node
     */
    void linkedlist__insert_head(struct LINKEDLIST * linkedlist, int value);


    /**
     * @brief Insert new element in linkedlist by tail
     * @param *linkedlist : LINKEDLIST address of linkedlist memory
     * @param value : integer that represent the value of new node
     */
    void linkedlist__insert_tail(struct LINKEDLIST * linkedlist, int value);


    /**
     * @brief Delete node in linkedlist by value
     * @param linkedlist : LINKEDLIST address of linkedlist memory
     * @param value : integer that represent the value of node to delete
     * @return int : value of the node deleted
     */
    int linkedlist__delete_node(struct LINKEDLIST * linkedlist, int value);


    /**
     * @brief Delete first node in linkedlist
     * @param *linkedlist : LINKEDLIST address of linkedlist memory
     * @return int : value of the node deleted
     */
    int linkedlist__delete_head(struct LINKEDLIST * linkedlist);

    /**
     * @brief Delete last node in linkedlist
     * @param *linkedlist : LINKEDLIST address of linkedlist memory
     * @return int : value of the node deleted
     */
    int linkedlist__delete_tail(struct LINKEDLIST * linkedlist);

    /**
     * @brief Get the first node that the value inside is equal than pass in parameter
     * @param *linkedlist : LINKEDLIST address of linkedlist memory
     * @param value : int represent the value to verify with all node's value
     * @return NODE : first node searched with value or nothing if not found
     */
    struct NODE linkedlist__search_node(struct NODE *head, struct NODE value);


    #pragma endregion Methods

    #endif
