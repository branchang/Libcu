/*
 * =====================================================================================
 *
 *       Filename:  shash.c
 *
 *    Description:  simple hash 不支持动态扩展
 *
 *        Version:  1.0
 *        Created:  10/16/2015 15:57:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

typedef struct  element_s{
    char *key;
    void *value;
    struct element_s *next;
}element_t;


typedef struct shash_t{
    int size;
    element_t **table;
}shash_t;

shash *shash_create(int num);

int shash_destroy(shash_t *hash);

//
int ahash_hash(shash_t *hash, char *key);

int shash_set(shash_t *hash, char *key, void* pvalue);

int shash_get(shash_t *hash, char *key, void** ppvalue);

shash *shash_create(int num){
    shash *h = NULL;
    h = (shash_t *)malloc(sizeof(shash_t));
    if (!h)
    {
        printf("malloc error %s %d !!", __func__, __LINE__);
        return h;
    }

    h->size = num;
    element_t table = (element_t *)malloc(sizeof(element_t *)* num);
    if(table)
        h->table = table;
    else{
        printf("malloc error %s %d !!", __func__, __LINE__);
        return NULL;
    }

    int i = 0;
    
    for(i=0;i<num;i++){
        h->table[i] = NULL;
    }

    return h; 
}


int shash_destory(shash_t *hash){

    if(!hash)
    {
        printf("error %s %d !!", __func__, __LINE__);
        return -1;
    }

    shash_t *h = hash;
    int i = 0;
    for(i=0;i<h->size;i++){
        if(h->table[i]){
            element_t *e = h->table[i];
            while(e){
                element_t *temp =e;
                if(temp->next){
                    e = temp->next;
                }
                free(temp);
                temp = NULL;
            }
            h->table[i] = NULL;
        }
    }
    free(hash);
    hash = NULL;
    return 0;
}

int ahash_hash(shash_t *hash, char *key){
    return 0;

}


/* Create a key-value pair. */
element_t *hash_newpair( char *key, char *value ,int size) {
	element_t *newpair;

	if( ( newpair = malloc( sizeof( element_t) ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->key = strdup( key ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->value = (void *)malloc(size)) == NULL ) {
		return NULL;
	}
    memcpy(newpair->value, value, size);

	newpair->next = NULL;

	return newpair;
}

int shash_set(shash_t *hash, char *key, void* pvalue, int size){

    if(!hash||!key||!pvalue){
        printf("error %s %d !!", __func__, __LINE__);
        return -1;
    }

    int index = ahash_set(hash, key);
    element_t *next = hash->table[index];
    element_t *last = NULL;
    // first is null, 从大到小的存储?
    //已经有的key只修改value数值
    while(next!=NULL && next->key!=NULL&& strcmp(key, next->key)>0 ){
        last = next;
        next = next->next;
    }
    
    //优先处理只改变参数值的方式
    if (next!=NULL && next->key!=NULL && strcmp(key, next->key) ==0)
    {
        free(next->value);
        next->value = pvalue;
    }else {

        //create new one 
        element_t *newe = hash_newpair(key, pvalue, size);

        if(next == hash->table[index])
        {
            //begin
            newe->next = hash->table[index]->next;
            hash->table[index] = newe;

        }else if(last == NULL)
        {
            //last 
            hash-table[index] = newe;

        }else {
            //middle
            newe->next = next;
            last->next = newe;
        }
    }
}

int shash_get(shash_t *hash, char *key, void** ppvalue){

    if(!hash||!key){
        printf("error %s %d !!", __func__, __LINE__);
        return -1;
    }

    int index = ahash_set(hash, key);
    pele = hash->table[index]; 

    while(pele!=NULL && pele->key!=NULL && strcmp(pele->key, key)>0)
    {
        pele = pele->next;
    }

    if(pele==NULL || pele->key==NULL || (strcmp(key, pele->key)!=0))
    {
        return -1;
    }else {
        *ppvalue = pele->value;
        return 0;
    }

}

