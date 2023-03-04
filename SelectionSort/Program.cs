// See https://aka.ms/new-console-template for more information

// Selection Sort

namespace Project
{
    struct LabelInt
    {
        public int val{get; set;}
        private int label{get; set;}

        // 這樣寫有點因為為了寫而寫
        public int Val
        {
            get
            {
                Console.Write($"<{label}>-");
                return this.val;
            }
            set
            {
                this.val = value;
            }
        }
        public LabelInt(int _val, int _label = 0)
        {
            this.val = _val;
            this.label = _label;
        }
    }

    
    internal class SortIntArray
    {
        private static void Main()
        {
            List<LabelInt> arr = new List<LabelInt>();

            arr.Add(new LabelInt(5, 1));
            arr.Add(new LabelInt(1, 1));
            arr.Add(new LabelInt(5, 2));
            arr.Add(new LabelInt(5, 3));
            arr.Add(new LabelInt(7, 1));
            arr.Add(new LabelInt(3, 1));

            SelectionSortWithLabelInt(arr);

            foreach(LabelInt i in arr)
            {
                Console.Write($"{i.Val} ");
            }
        }
        public static void SelectionSortWithLabelInt(List<LabelInt> arr)
        {
            int min_index = 0;
            LabelInt tmp;
            for(int i = 0; i < arr.Count; i++)
            {
                min_index = i;
                for(int j = i + 1; j < arr.Count; j++)
                {
                    if(arr[j].val < arr[min_index].val) min_index = j;
                }
                tmp = arr[min_index];
                arr[min_index] = arr[i];
                arr[i] = tmp;
            }            
        }
        public static void SelectionSort(int[] arr)
        {            
            int min_index = 0, tmp;
            for(int i = 0; i < arr.Length; i++)
            {
                min_index = i;
                
                for(int j = i + 1; j < arr.Length; j++)
                {
                    if(arr[j] < arr[min_index]) min_index = j;
                }
                tmp = arr[min_index];
                arr[min_index] = arr[i];
                arr[i] = tmp;
            }            
        }
    }
}