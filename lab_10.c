#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 26

typedef struct Trie Trie;

// Trie structure
struct Trie
{	
    Trie* children[N];
    int is_leaf;
};

// Inserts the word to the trie structure
void insert(struct Trie *pTrie, char *word)
{
    struct Trie* curr = pTrie;
    while (*word)
    {
        if (curr->children[*word - 'a'] == NULL) {
            curr->children[*word - 'a'] = createTrie();
        }
        curr = curr->children[*word - 'a'];
        word++;
    }
    curr->is_leaf = 1;
}

// computes the number of occurances of the word
int numberOfOccurances(struct Trie *pTrie, char *word)
{
    Trie* temp = pTrie;

    for(int i=0; word[i]!='\0'; i++)
    {
        int position = word[i] - 'a';
        if (temp->children[position] == NULL)
            return 0;
        temp = temp->children[position];
    }
    if (temp != NULL && temp->is_leaf == 1)
        return 1;
    return 0;
}

// deallocate the trie structure
struct Trie *deallocateTrie(struct Trie *pTrie)
{
    for(int i=0; i<N; i++) {
        if (pTrie->children[i] != NULL) {
            deallocateTrie(pTrie->children[i]);
        }
        else {
            continue;
        }
    }
    free(pTrie);
}

// Initializes a trie structure
struct Trie *createTrie()
{
    Trie *node = (Trie*)malloc(sizeof(Trie));
    node->is_leaf = 0;
 
    for (int i = 0; i < N; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// this function will return number of words in the dictionary,
// and read all the words in the dictionary to the structure words
int readDictionary(char *filename, char **pInWords)
{
    Trie *TempTrie = createTrie();
    int i = 0;
    FILE * fp;
    fp = fopen( filename, "r");
    while(!feof(fp)){
        fgets(pInWords, 256, fp);
        insert(TempTrie, pInWords[i]);
        i++;
    }
    fclose (fp);
    return i;
}

int main(void)
{
	char *inWords[256];
	
	//read the number of the words in the dictionary
	int numWords = readDictionary("dictionary.txt", inWords);
	for (int i=0;i<numWords;++i)
	{
		printf("%s\n",inWords[i]);
	}
	
	struct Trie *pTrie = createTrie();
	for (int i=0;i<numWords;i++)
	{
		insert(pTrie, inWords[i]);
	}
	// parse lineby line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	for (int i=0;i<5;i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurances(pTrie, pWords[i]));
	}
	pTrie = deallocateTrie(pTrie);
	if (pTrie != NULL)
		printf("There is an error in this program\n");
	return 0;
}