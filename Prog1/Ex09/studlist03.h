/* Record構造体の宣言 */
typedef struct {
  int id;
  char surname[12];
  char givenname[12];
  int age;
} Record;

/* node構造体の宣言 */
typedef struct node *NodePointer;
struct node {
  Record data;
  struct node *next;
};

/* プロトタイプ宣言 */
NodePointer insert(Record); /* 新しいノード挿入関数 */
NodePointer finditem(int); /* リスト内の重複するノード検索関数 */
void listprint(void); /* リスト内データの表示関数 */
NodePointer make_1node(Record, NodePointer); /* 新しいノード作成関数 */
NodePointer delete(int);

/* グローバル変数 head */
NodePointer head;