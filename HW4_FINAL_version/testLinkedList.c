#include "LinkedList.h"
//test file

int compare_string(void *A,void *B){
  int index;
  index=malloc(sizeof(int));
  char *a,*b;
  a=(char*)A;
  b=(char*)B;
  if(A==B){
    index=1;
  }else{
    index=0;
  }
  return index;
}


int main(int argc, char *argv[]) {
  // int success_index;
  // success_index=compare_string("hello","www");
  // printf("%d\n",success_index );


	printf("Creating list...\n");
	LIST only_list = create_new_list();

	printf("Inserting string 'hi'...\n");
	insert_end(only_list, "hi");

	printf("Inserting string 'my'...\n");
	insert_end(only_list, "my");

	printf("Inserting string 'name'...\n");
	insert_end(only_list, "name");

	printf("Inserting string 'is'...\n");
	insert_end(only_list, "is");

	printf("Inserting string 'Spicy'...\n");
	insert_end(only_list, "spicy");

	 displayList_front_to_behind(only_list, print_string);

	  printf("\nDeleting string 'name'...\n");
	  delete_it(only_list, "name",compare_string);

	 printf("\nDeleting string 'owl'...\n");
	 delete_it(only_list, "owl",compare_string );

	displayList_front_to_behind(only_list, print_string);

	// printf("\nObtaining item at index 3 ...\n");
	// print_specific_item(only_list, 3,print_string);

	printf("\nTest complete.\n");
	return 0;
}
