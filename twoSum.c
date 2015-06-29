typedef struct a_num {
        int num;
        int index;
    } a_num;
    
int compareByNum(const void *a, const void *b);
void sort(int *a);

int *twoSum(int numbers[], int n, int target) {
    
    static int a[2];
    
    a_num *anum = malloc(sizeof(a_num) * n);
    
    for (int i = 0; i < n; i++) {
        anum[i].num = numbers[i];
        anum[i].index = i;
    }
    //a[0]=anum[0].num;
    //a[1]=anum[1].num;
    
    qsort(anum, n, sizeof(anum[0]), compareByNum);
    
    int min = 0;
    int max = n-1;
    
    while (min < max) {
        int sum = anum[min].num + anum[max].num;
        if (sum < target) {
            min++;
        }
        else if (sum > target) {
            max--;
        }
        else {
            a[0] = anum[min].index + 1;
            a[1] = anum[max].index + 1;
            break;
        }
    }
    free(anum);
    sort(a);
    return a;
}

int compareByNum(const void *a, const void *b) {
    const a_num *p = a;
    const a_num *q = b;
    
    return (p->num - q->num);
}

void sort(int *a) {
    int tem;
    if (a[0] > a[1]) {
        tem = a[0];
        a[0] = a[1];
        a[1] = tem;
    }
}