
#include "sorting2.cpp"

int main(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<int> array;
    for(int i=1; i<DATA_SAMPLE; ++i) array.push_back(i);

    // Shuffle numbers
    shuffleArray(array);

    // BUBBLE SORT
    cmp = 0, swp = 0;
    std::chrono::nanoseconds bubbleDuration = std::chrono::nanoseconds(0);
    bubbleSort(array, bubbleDuration);
    shuffleArray(array);
    bubbleSort(array, bubbleDuration);
    shuffleArray(array);
    bubbleSort(array, bubbleDuration);
    shuffleArray(array);
    std::cout<<"BUBBLE SORT:"<<std::endl;
    std::cout<<"Average exec. time - "<<bubbleDuration.count()*1e-9/3<<" seconds. Average comparisons - "<<cmp/3<<", average attributions - "<<swp<<std::endl;

    // SHAKER SORT
    cmp = 0, swp = 0;
    std::chrono::nanoseconds shakerDuration = std::chrono::nanoseconds(0);
    cocktailShakerSort(array, shakerDuration);
    shuffleArray(array);
    cocktailShakerSort(array, shakerDuration);
    shuffleArray(array);
    cocktailShakerSort(array, shakerDuration);
    shuffleArray(array);
    std::cout<<"SHAKER SORT:"<<std::endl;
    std::cout<<"Average exec. time - "<<shakerDuration.count()*1e-9/3<<" seconds. Average comparisons - "<<cmp/3<<", average attributions - "<<swp<<std::endl;
    
    // COMB SORT
    cmp = 0, swp = 0;
    std::chrono::nanoseconds combDuration = std::chrono::nanoseconds(0);
    combSort(array, combDuration);
    shuffleArray(array);
    combSort(array, combDuration);
    shuffleArray(array);
    combSort(array, combDuration);
    shuffleArray(array);
    std::cout<<"COMB SORT:"<<std::endl;
    std::cout<<"Average exec. time - "<<combDuration.count()*1e-9/3<<" seconds. Average comparisons - "<<cmp/3<<", average attributions - "<<swp<<std::endl;

    // SELECTION SORT
    cmp = 0, swp = 0;
    std::chrono::nanoseconds selectionDuration = std::chrono::nanoseconds(0);
    selectionSort(array, selectionDuration);
    shuffleArray(array);
    selectionSort(array, selectionDuration);
    shuffleArray(array);
    selectionSort(array, selectionDuration);
    shuffleArray(array);
    std::cout<<"SELECTION SORT:"<<std::endl;
    std::cout<<"Average exec. time - "<<selectionDuration.count()*1e-9/3<<" seconds. Average comparisons - "<<cmp/3<<", average attributions - "<<swp<<std::endl;

    // INSERTION SORT
    cmp = 0, att = 0;
    std::chrono::nanoseconds insertionDuration = std::chrono::nanoseconds(0);
    insertionSort(array, insertionDuration);
    shuffleArray(array);
    insertionSort(array, insertionDuration);
    shuffleArray(array);
    insertionSort(array, insertionDuration);
    shuffleArray(array);
    std::cout<<"INSERTION SORT:"<<std::endl;
    std::cout<<"Average exec. time - "<<insertionDuration.count()*1e-9/3<<" seconds. Average comparisons - "<<cmp/3<<", average attributions - "<<att/3<<std::endl;

    // GNOME SORT
    cmp = 0, swp = 0;
    std::chrono::nanoseconds gnomeDuration = std::chrono::nanoseconds(0);
    gnomeSort(array, gnomeDuration);
    shuffleArray(array);
    gnomeSort(array, gnomeDuration);
    shuffleArray(array);
    gnomeSort(array, gnomeDuration);
    shuffleArray(array);
    std::cout<<"GNOME SORT:"<<std::endl;
    std::cout<<"Average exec. time - "<<gnomeDuration.count()*1e-9/3<<" seconds. Average comparisons - "<<cmp/3<<", average attributions - "<<swp<<std::endl;

    // SHELL SORT
    cmp = 0, att = 0;
    std::chrono::nanoseconds shellDuration = std::chrono::nanoseconds(0);
    shellSort(array, shellDuration);
    shuffleArray(array);
    shellSort(array, shellDuration);
    shuffleArray(array);
    shellSort(array, shellDuration);
    shuffleArray(array);
    std::cout<<"SHELL SORT:"<<std::endl;
    std::cout<<"Average exec. time - "<<shellDuration.count()*1e-9/3<<" seconds. Average comparisons - "<<cmp/3<<", average attributions - "<<att/3<<std::endl;

    // -------------------------------------------------------OPTIMAL SORTING ALGORITHMS----------------------------------------------------------------------------
    std::cout<<"--------------- OPTIMAL SORTING ALGORTIHMS ---------------"<<std::endl;
    
    // QUICK SORT
    cmp = 0, att = 0;
    std::chrono::nanoseconds quickDuration = std::chrono::nanoseconds(0);
    quickSort(array, 0, array.size()-1, quickDuration);
    shuffleArray(array);
    quickSort(array, 0, array.size()-1, quickDuration);
    shuffleArray(array);
    quickSort(array, 0, array.size()-1, quickDuration);
    shuffleArray(array);
    std::cout<<"QUICK SORT:"<<std::endl;
    std::cout<<"Average exec. time - "<<quickDuration.count()*1e-9/3<<" seconds. Average comparisons - "<<cmp/3<<", average attributions - "<<att/3<<std::endl;
    
    // TREE SORT
    cmp = 0, att = 0;
    std::chrono::nanoseconds treeDuration = std::chrono::nanoseconds(0);
    treeSort(array, treeDuration);
    shuffleArray(array);
    treeSort(array, treeDuration);
    shuffleArray(array);
    treeSort(array, treeDuration);
    shuffleArray(array);
    std::cout<<"TREE SORT:"<<std::endl;
    std::cout<<"Average exec. time - "<<treeDuration.count()*1e-9/3<<" seconds. Average comparisons - "<<cmp/3<<", average attributions - "<<att/3<<std::endl;

    // MERGE SORT
    cmp = 0, att = 0;
    std::chrono::nanoseconds mergeDuration = std::chrono::nanoseconds(0);
    mergeSort(array, 0, array.size()-1, mergeDuration);
    shuffleArray(array);
    mergeSort(array, 0, array.size()-1, mergeDuration);
    shuffleArray(array);
    mergeSort(array, 0, array.size()-1, mergeDuration);
    shuffleArray(array);
    std::cout<<"MERGE SORT:"<<std::endl;
    std::cout<<"Average exec. time - "<<treeDuration.count()*1e-9/3<<" seconds. Average comparisons - "<<cmp/3<<", average attributions - "<<att/3<<std::endl;

    // HEAP SORT
    cmp = 0, att = 0;
    std::chrono::nanoseconds heapDuration = std::chrono::nanoseconds(0);
    heapSort(array, heapDuration);
    shuffleArray(array);
    heapSort(array, heapDuration);
    shuffleArray(array);
    heapSort(array, heapDuration);
    shuffleArray(array);
    std::cout<<"HEAP SORT:"<<std::endl;
    std::cout<<"Average exec. time - "<<treeDuration.count()*1e-9/3<<" seconds. Average comparisons - "<<cmp/3<<", average attributions - "<<att/3<<std::endl;

    // STRAND SORT
    cmp = 0, att = 0;
    std::chrono::nanoseconds strandDuration = std::chrono::nanoseconds(0);
    strandSort(array, strandDuration);
    shuffleArray(array);
    strandSort(array, strandDuration);
    shuffleArray(array);
    strandSort(array, strandDuration);
    shuffleArray(array);
    std::cout<<"STRAND SORT:"<<std::endl;
    std::cout<<"Average exec. time - "<<treeDuration.count()*1e-9/3<<" seconds. Average comparisons - "<<cmp/3<<", average attributions - "<<att/3<<std::endl;


    return 0;
}