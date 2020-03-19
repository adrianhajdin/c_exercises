void bubble_sort(int array[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            if(array[j - 1] > array[j]) {
                int tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            }
        }   
    }
}