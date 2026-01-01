#include<stdio.h> 
#include <malloc.h>
#define MAX 5

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

int IsEmpty(struct node *,struct node *);
int IsFull(struct node *,struct node *);
void Create(struct node **,struct node **);
void Display(struct node *,struct node *);
void DeleteAll(struct node **,struct node **);
void Insert(struct node **,int); 
int Delete(struct node *,struct node *,int); 
void Defragement(struct node **,struct node **,struct node **);

int main(void)
{
    int iPos;
    int iChoice;
    struct node *pFirst = NULL;
    struct node *pLast = NULL;
    struct node *pCurrent = NULL;

    Create(&pFirst,&pLast);
    pCurrent = pFirst;
    // Display(pFirst,pLast);
    // printf("%d",CountNodes(pFirst,pLast));
    do
    {
        printf("\n1.Insert \n");
        printf("2.Delete \n");
        printf("3.Defragement \n");
        printf("4.Exit \n");
        printf("Enter your Choice:\t");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                if(IsFull(pFirst,pLast))
                    printf("\nList Is Full\n");
                else
                {
                    printf("\nEnter Data:\t");
                    scanf("%d",&iPos);
                    Insert(&pCurrent,iPos);
                    Display(pFirst,pLast);
                }
                break;
            case 2:
                if(IsEmpty(pFirst,pLast))
                    printf("\nList is Empty\n");
                else
                {
                    printf("\nEnter Position:\t");
                    scanf("%d",&iPos);
                    
                    iPos = Delete(pFirst,pLast,iPos);

                    if(0 == iPos)
                    {
                        printf("\nData already Deleted!\n");
                        Display(pFirst,pLast);
                    }
                    else if(iPos != -1)
                    {
                        printf("\nDeleted Data is %d\n",iPos);
                        printf("\nList after deleting data:\n");
                        Display(pFirst,pLast);

                    }
                }
                break;

                case 3:
                    if(!IsFull(pFirst,pLast) && !IsEmpty(pFirst,pLast))
                        Defragement(&pCurrent,&pFirst,&pLast);
                    Display(pFirst,pLast);
                    break;

                case 4:
                    break;

                default:
                    printf("\nInvaid Choice!\n");

        }

    }while(4 != iChoice);
    
    if(NULL != pFirst)
    {
        DeleteAll(&pFirst,&pLast);
        pFirst = pLast = NULL;
    }

    return 0;
}

int IsEmpty(struct node *pHead,struct node *pTail)
{
    if(NULL == pHead)
        return 1;

    do
    {
        if(0 != pHead->iData)
            return 0;

        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

    return 1;
}


int IsFull(struct node *pHead,struct node *pTail)
{
    if(NULL == pHead)
        return 0;

    do
    {
        if(0 == pHead->iData)
            return 0;

        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

    return 1;
}

void Create(struct node **ppHead,struct node **ppTail)
{
    int iCount;
    struct node *pNewNode = NULL;

    for(iCount = 0;iCount < MAX; iCount++)
    {
        pNewNode = (struct node *)malloc(sizeof(struct node));
        if(NULL == pNewNode)
        {
            printf("Memory Allocation Failed!.\n");
            return;
        }

        pNewNode->iData = 0;
        if(NULL == *ppHead)
        {
            *ppHead = pNewNode;
            *ppTail = pNewNode;
        }
        else
        {
            pNewNode->pNext = *ppHead;
            (*ppHead)->pPrev = pNewNode;
            *ppHead = pNewNode;
        }
        
        (*ppHead)->pPrev = *ppTail;
        (*ppTail)->pNext = *ppHead;
    }
}

void Display(struct node *pHead,struct node *pTail)
{
    if(NULL==pHead)
    {
        printf("\nList is empty\n");
        return;
    }

    do
    {
        printf("<-|%d|->",pHead->iData);
        pHead=pHead->pNext;
    }while(pHead!=pTail->pNext);

    // do
    // {
        // printf("<-|%d|%d|%d|->",pHead->pPrev,pHead->iData,pHead->pNext);
        // pHead=pHead->pNext;
    // }while(pHead!=pTail->pNext);

    printf("\n");

}


void DeleteAll(struct node **ppHead,struct node **ppTail)
{
    struct node *pTemp=NULL;
    if(NULL==*ppHead)
        return;

    (*ppTail)->pNext=NULL;

    while(*ppHead!=NULL)
    {
        pTemp=*ppHead;
        (*ppHead)=(*ppHead)->pNext;
        pTemp->pNext=NULL;
        pTemp->pPrev=NULL;
        free(pTemp);
    }

    *ppTail=NULL;
}


int Delete(struct node *pHead,struct node *pTail,int iPos)
{
    int iCount;

    if(iPos<=0 || iPos > MAX)
    {
        printf("Invalid position!\n");
        return -1;
    }

    if(iPos == 1)
    {
        iCount = pHead->iData; 
        pHead->iData = 0;

        return iCount;
    }    
    if(iPos == MAX)
    {
        iCount = pTail->iData;
        pTail->iData = 0;
        return iCount;
    }
        
    iCount = 1;
    while(iCount < iPos)
    {
        iCount++;
        pHead = pHead->pNext;
    }

    iCount = pHead->iData;
    pHead->iData = 0;

    return iCount;
}

void Insert(struct node **ppCurrent,int iData)
{
    // struct node *pTemp = *ppCurrent;
    
    // do
    // {
    //     if(0 == (*ppCurrent)->iData)
    //     {
    //         (*ppCurrent)->iData = iData;
    //         return;
    //     }

    //     *ppCurrent = (*ppCurrent)->pNext; 
    // }while(*ppCurrent != pTemp);

    while(1)
    {
        if(0 == (*ppCurrent)->iData)
        {
            (*ppCurrent)->iData = iData;
            return;
        }

        *ppCurrent = (*ppCurrent)->pNext;
    }
}

// void Defragement(struct node **ppCurrent,struct node *pHead,struct node *pTail)
// {
    // struct node *pTemp = NULL;
    // // printf("\na\n");
    
    // if(NULL == pHead)
    //     return;


    // *ppCurrent = pHead;

    // do
    // {
    //     if(0 == pHead->iData && pHead != pTail->pNext)
    //     {
    //         pTemp = pHead;
    //         while(pTemp->pPrev != pTail && pTemp->pPrev->iData != 0 )
    //         {
    //             // printf("\na\n");
    //             // Display(pFirst,pLast);

    //             pTemp->iData = pTemp->iData + pTemp->pPrev->iData; 
    //             pTemp->pPrev->iData = pTemp->iData - pTemp->pPrev->iData; 
    //             pTemp->iData = pTemp->iData - pTemp->pPrev->iData; 

    //             pTemp = pTemp->pPrev;
    //         }
    //     }

    //     pHead = pHead->pNext;
    //     // printf("\n%d\n",pHead->iData);
    // }while(pHead != pTail->pNext);
    
// }

// void Defragement(struct node **ppCurrent, struct node **ppHead, struct node **ppTail)
// {
//     struct node *pTemp1 = NULL;
//     struct node *pTemp2 = NULL;
//     struct node *pTemp3 = NULL;

//     if(NULL == *ppHead)
//         return;

//     pTemp1 = *ppCurrent = *ppHead;

//     do
//     {
//         if(0 == pTemp1->iData && pTemp1 != (*ppTail)->pNext)
//         {
//             // printf("asd");
//             pTemp2 = pTemp1;
//             pTemp1 = pTemp1->pPrev;
//             while(pTemp2->pPrev != *ppTail && pTemp2->pPrev->iData != 0 )
//             {   
//                 pTemp3 = pTemp2->pPrev;
                
//                 pTemp2->pNext->pPrev = pTemp3;
//                 pTemp3->pNext = pTemp2->pNext;

//                 pTemp2->pNext = pTemp3;
//                 pTemp2->pPrev = pTemp3->pPrev;
//                 pTemp3->pPrev = pTemp2;

//                 if(*ppTail == pTemp2->pPrev)
//                 {
//                     *ppHead = pTemp2;
//                     (*ppTail)->pNext = *ppHead;
//                 }

//                 pTemp2 = pTemp2->pPrev;
//                 ////////////////////////////////////
//                 // pTemp2 = pTemp1->pPrev;
//                 // pTemp2 = pTemp1->pNext;
//                 // pTemp3 = pTemp1->pPrev;

//                 // pTemp3->pNext = pTemp1->pNext;
//                 // pTemp1->pNext->pPrev = pTemp3;
                
//                 // if(pTemp3->pPrev == *ppTail)
//                 // {
//                 //     *ppHead = pTemp1;
//                 //     (*ppTail)->pNext = pTemp1; 
//                 // }

//                 // pTemp1->pPrev = pTemp3->pPrev;
//                 // pTemp1->pNext = pTemp3;
//                 /////////////////////////////////////////
//                 // pTemp1->pNext->pPrev = pTemp2;
//                 // pTemp1->pPrev = pTemp2->pPrev;
//                 // pTemp2->pNext = pTemp1->pNext;
//                 // pTemp1->pNext = pTemp2;
//                 // pTemp2->pPrev = pTemp1;

//                 // if(pTemp1->pPrev == *ppTail)
//                 // {
//                 //     (*ppHead) = pTemp1;
//                 //     (*ppTail)->pNext = (*ppHead);
//                 // }             
//                 // pTemp1->pPrev->pNext = pTemp1;
//                 /////////////////////////////////////////////////////////////

//             }
//         }

//         pTemp1 = pTemp1->pNext;
//     }while(pTemp1 != (*ppTail)->pNext);
// }

void Defragement(struct node **ppCurrent, struct node **ppHead, struct node **ppTail)
{
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    if(NULL == *ppHead)
        return;

    pTemp1 = *ppHead;

    do
    {
        if(0 == pTemp1->iData && pTemp1 != (*ppTail)->pNext)
        {
            pTemp2 = pTemp1->pPrev;
            while(pTemp2 != *ppTail && pTemp2->iData != 0 )
            {   
                pTemp1->pNext->pPrev = pTemp2;
                pTemp2->pNext = pTemp1->pNext;

                if(pTemp1 == *ppTail)
                    *ppTail = pTemp2;

                pTemp1->pNext = pTemp2;
                pTemp1->pPrev = pTemp2->pPrev;

                pTemp2->pPrev = pTemp1;
                pTemp1->pPrev->pNext = pTemp1;      
                pTemp2 = pTemp1->pPrev;
                
                if(pTemp1->pPrev == *ppTail)
                {
                    *ppHead = pTemp1;
                    (*ppTail)->pNext = *ppHead;
                }           
            }
        }

        pTemp1 = pTemp1->pNext;
    }while(pTemp1 != (*ppTail)->pNext);

    *ppCurrent = *ppHead;
}