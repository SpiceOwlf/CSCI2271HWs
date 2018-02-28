//HW2 B.c function
#include "LinkedListW.h"



word_t *update(word_t *head, word_t *new){
	word_t *p;
	if (head==NULL) return new;
	p = head;
	if (same(p,new)){
			p->frequency++;
			return head;
		}
	while (p->next != NULL){
		if (same(p,new)){
			p->frequency++;
			return head;
		}
		p = p->next;
	}
	if (same(p,new)){
			p->frequency++;
			return head;
		}
	p->next = new;
	return head;
}


char *getWord(int *size){
	int index=0;
	char *p;
	char item;
	p = (char*) malloc (sizeof(char));
	while (1) {
		item = getchar();
		if (item == '\n' || item == ' ') break;
		*(p+index) = item;
		index++;
		p = (char*) realloc (p,index+1);
	}
	*(p+index)='\0';//give '\0' to the last character
	*size = index;
	return p;
}


word_t *createWord(char *word, int len){
	word_t *p;
	p = malloc(sizeof(word_t));
	p->w = word;
	p->length = len;
	p->frequency = 1;
	return p;
}



int Stop(char *word, int size){
	if (size==4){
		if (*word != 'S') return 0;
		if (*(word+1) != 'T') return 0;
		if (*(word+2) != 'O') return 0;
		if (*(word+3) != 'P') return 0;
		return 1;
	}
	return 0;
}



int same(word_t *old, word_t *new){
	int len=old->length;
	int i;
	char *p,*q;
	p = old->w;
	q = new->w;
	if (old->length != new->length) return 0;
	else{
		for (i=0;i<len;i++){
			if (*(p+i)!=*(q+i)) return 0;
		}
	}
	return 1;
}


int get_most(word_t *head){
	int most=0;
	word_t *p;
	p = head;
	if (head==NULL) return 0;
	while (p != NULL){
		if (most < p->frequency) most = p->frequency;
		p = p->next;
	}
	return most;
}



word_t **most_freq(word_t *head, int most, int *length){
	int index=0;
	word_t *p;
	word_t **array;
	array = malloc(8);
	p = head;
	while (p!=NULL){
		if (p->frequency == most){
			*(array+index) = p;
			index++;
			array = realloc(array,8*(index+1));
		}
		p = p->next;
	}
	*length = index;
	return array;
}



void printWord(word_t *word){
	char *p;
	p = word->w;
	int size = word->length;
	int i;
	for (i=0;i<size;i++){
		printf ("%c",*(p+i));
	}
}


void printList(word_t *head){
	word_t *p;
	p = head;
	while (p!=NULL){
		printWord(p);
		printf("   %d\n",p->frequency);
		p = p->next;
	}
}


void printFreqList(word_t **list, int size){
//printWord(*(list));
	word_t *p;
	int index=0;
	while (index<size){
		p = *(list+index);
		printWord(p);
		printf("\n");
		index++;
	}
}



void freeAll(word_t *head){
	word_t *p;
	while (p!=NULL){
		free(p->w);
		free(p);
		p=p->next;
	}
}


int main(){
	int word_size,freq,listLen;
	word_t *head,*new;
	word_t **freq_list;
	head=NULL;
	char *p;
	printf("Enter the text:\n");
	while (1){
		//everytime accept a sentence,with getword;
		//assign it a line numer, with i, i++
		//and give it to the struct
		p = getWord(&word_size);
		if (Stop(p,word_size)) break;
		if (word_size!=0){
			new = createWord(p,word_size);
			head = update(head,new);
		}
	}
	printf("Word list:\n");
	printList(head);
	freq = get_most(head);
	freq_list = most_freq(head, freq, &listLen);
	printf("Words with most frequency:\n");
	printFreqList(freq_list,listLen);
	freeAll(head);
	freeAll(new);
	free(freq_list);
}
