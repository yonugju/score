

typedef struct _conecter{

	int *base;
	int size;
	int capacity;

}container;

void push_back(container *vector, int value);
void insert(container *vector, int value1, int value2);	//ex) value1열에 value2값 insert
void erase(container *vector, int value1, int value2);	//ex) value1부터 value2값까지 삭제
void size(container *vector);
void capacity(container *vector);
void begin(container *vector);
void end(container *vector);
void back(container *vector);
void resize(container *vector, int value1);
void shrink_to_fit(container *vector);
void pop_back(container *vector, int value);
void print(container *vector);
