#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/** 
 * @file LinkedList.h 
 * @brief A Sequential Data Structure that support FIFO and LIFO 
 */

// Todo List
// DONE Make LinkedList accept generic
// DONE Delete search function
// DONE Make print format callback for printList()
// DONE Use size_t for length/size related
// DONE Add NULL handling for insertion function
// DONE Add Documentation
// DONE Compile to .so file

#include <stddef.h>

/** @defgroup MACRO 
 *  @brief Macro functions for getting Node's data conveniently
 *  @{
 */

/**
 * @brief Macro to safely return node data with type casting
 * @param type: Data type for type casting
 * @param node: Individual Node in the LinkedList
 * @return value of node based on type casted
 * @note Only use this macro in callback function for printList 
 * @see printList
 */
#define GET_NODE_DATA(type, node) (*((type*)((node)->data)))

/**
 * @brief Macro to return first Node in LinkedList with type casting
 * @param type: Data type for type casting
 * @param list: A LinkedList
 * @return value of node based on type casted
 * @see peekHead
 */
#define PEEK_HEAD(type, list) (*(type*)peekHead(list))

/**
 * @brief Macro to return last Node in LinkedList with type casting
 * @param type: Data type for type casting
 * @param list: A LinkedList
 * @return value of node based on type casted
 * @see peekTail
 */
#define PEEK_TAIL(type, list) (*(type*)peekTail(list))

/** @} */


/**
 * @struct Node 
 * @brief Doubly-Linked Node for LinkedList
 */
typedef struct Node {
	void* data;        /**< Node's data (generic)    */
	struct Node* next; /**< Pointer to next Node     */
	struct Node* prev; /**< Pointer to previous Node */
} Node;

/** 
 * @struct Linked List
 * @brief Doubly-LinkedList that store generic data pointers
 */
typedef struct LinkedList {
	Node* head;      /**< first node of LinkedList */
	Node* tail;      /**< last node of LinkedList  */
	size_t length;   /**< length of LinkedList     */
	size_t nodeSize; /**< Size of Node's data type */
} LinkedList;


/** @defgroup Initialize
 *  @brief Functions like Constructors to create instances
 *  @{
 */

/** 
 * @brief Functions to create Node instance
 * @param data: Value of Node
 * @param dataSize: Size of data type
 * @return Pointer of Node
 * @note Don't use this function because LinkedList was handle it
 */
Node* newNode(void* data, size_t dataSize);

/**
 * @brief Functions to create LinkedList instance
 * @return Pointer of LinkedList
 * @param dataSize: Size of data type
 */
LinkedList* newList(size_t dataSize);

/** @} */


/** @defgroup Getter Functions 
 *  @brief Functions to safely retrieve LinkedList Node and metadata 
 *  @{
 */

/** 
 * @brief Peeking front Node's value in the LinkedList 
 * @param list: Pointer of LinkedList
 * @return void pointer of Node
 */
void* peekHead(const LinkedList* list);

/** 
 * @brief Peeking back Node's value in the LinkedList 
 * @param list: Pointer of LinkedList
 * @return void pointer of Node
 */
void* peekTail(const LinkedList* list);

/** 
 * @brief Accessing length of LinkedList 
 * @return Length of LinkedList
 */
size_t lengthList(const LinkedList* list);

/** @} */


/** @defgroup LinkedList Insertion
 *  @brief Functions related to insertion
 *  @{
 */

/** 
 * @brief push new node at front
 * @note Use compound literals if you want push value directly
 */
void pushAtHead(LinkedList* list, void* newData);

/** 
 * @brief push new node at back 
 * @note Use compound literals if you want push value directly
 */
void pushAtTail(LinkedList* list, void* newData); 

/** 
 * @brief push new node at desired position
 * @note Use compound literals if you want push value directly
 */
void insertAt(LinkedList* list, void* newData, size_t index);

/** @} */


/** @defgroup LinkedList Deletion
 *  @brief Functions related to deletion
 *  @{
 */

/** @brief Remove Node at the front */
void popAtHead(LinkedList* list); 

/** @brief Remove Node at the back */
void popAtTail(LinkedList* list); 

/** @brief Remove Node at the desired position */
void deleteAt(LinkedList* list, size_t index);

/** @} */

/** @defgroup Misc.
 *  @{
 */

/**
 * @brief Print each Node in the LinkedList 
 * @param printNode: Callback to print each node
 */
void printList(LinkedList* list, void (*printNode)(Node* current));

/** 
 * @brief Accessing Node in LinkedList 
 * @return Pointer of Node
 * @warning This function doesn't return a copy of Node and can cause undefined behavior if not be careful
 */
Node* at(LinkedList* list, size_t index);

/** @brief Free entire LinkedList */
void freeList(LinkedList* list);

/** @} */

#endif
