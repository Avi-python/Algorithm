
template<class T>
int RadixSort(T* a, int *link, const int d, const int r, const int n)
{  
    // d-digit, radix-r(這個radix就是可以說成是我們的桶子的數量)
    // Sorting within a digit is done using a bin sort (就是Counting sort).
    
    int e[r], f[r]; 
    // 宣告陣列，用儲存index，意味 end、first 之意，表達一個一個queue的頭和尾
    // 這邊意即bin的意思，分成一個一個桶子。
    int first = 1;
    for(int i = 1; i < n; i++) link[i] = i + 1; // 接成一個chain的感覺
    link[n] = 0; // link表示對應index之a陣列中的元素(a[index])指向的下一個元素之index。

    for(int i = d - 1; i >= 0; i--)
    { // Sort on Digit i
        fill(f, f + r, 0); // initialize 陣列成為都為0的arr
        for(int current = first; current; current = link[current])
        {
            int k = digit(a[current], i, r); 
            // digit(a[i], j, r) returns the j-th radix-r digit(from the left)
            // of a[i]'s key. Each digit is in the range is [0, r).
            // 我們這邊是只取一個位數一個位數分組
            if(f[k] == 0) f[k] = current;
            else link[e[k]] = current;
            // 因為f[k]是其中一個queue的起頭指向array a裡的index，
            // 如果 == 0 表示是空的，讓他做頭
            // else 就跟queue.push一樣，只是我們用f, e, index做紀錄
            e[k] = current;
            // 也就是把當前queue的尾巴指向下一個元素(link[e[k]] = current)，
            // 尾巴變成那個"下一個元素"(e[k] = current)。
        }

        // 下面這個第二個for大有搞頭
        // 概念上就是按照我們分好的queue，從代表該位數為0開始到9，
        // 把每個數字一個一個dequeue出來最後就會是當前位數sort好的形式。 
        int j;
        for(j = 0; !f[j]; j++); // find first nonempty queue
        first = f[j];
        int last = e[j];
        for(int k = j + 1; k < r; k++)
        {
            if(f[k]) // 如果這個基數queue不為空
            {
                link[last] = f[k]; 
                // 因為我們link已經連結好內部狀況，我們只需把queue和queue之間頭尾串接
                // link[last] = f[k]就是把我的尾巴和下一個基數queue(更高的基數)的頭連接。
                last = e[k]; // last就成為下一個基數queue的尾巴。
            }
        }
        link[last] = 0; // 相當於把所有queue刪掉。
    }
    return first;
}