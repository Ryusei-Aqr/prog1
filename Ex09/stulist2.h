/* struct declaration */
typedef struct {
  int id;
  char name[15];
  int score[3];
}Record;

typedef struct node *NodePointer;

struct node{
  Record data;
  NodePointer next;
};

/* prototype declaration */
NodePointer insert(Record);
/*削除関数*/
NodePointer delete(int);
NodePointer finditem(int);
void listprint(void);
NodePointer make_1node(Record , NodePointer);

/* Global Variable head */
NodePointer head;
