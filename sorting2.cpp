#include "sorting2.h"

int cmp;
int swp;
int att;

void shuffleArray(std::vector<int>& array){
    auto seed = std::rand();
    auto rnd = std::default_random_engine(seed);
    std::shuffle(array.begin(), array.end(), rnd);
}

void bubbleSort(std::vector<int>& array, std::chrono::nanoseconds& duration){
    auto begin = std::chrono::steady_clock::now();
    for(int i=0; i<array.size()-1; ++i){
        for(int j=0; j<array.size()-1; ++j){
            if(array[j]>array[j+1]){
                std::swap(array[j], array[j+1]);
                ++swp;
            }
            ++cmp;
        }
    }
    auto end = std::chrono::steady_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}

void cocktailShakerSort(std::vector<int>& array, std::chrono::nanoseconds& duration){
    int n = array.size();
    auto begin = std::chrono::steady_clock::now();
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(array[j]<array[j-1]){
                std::swap(array[j], array[j-1]);
                ++swp;
            }
            ++cmp;
        }
        --n;
        for(int k=n-1; k>i; --k){
            if(array[k]<array[k-1]){
                std::swap(array[k], array[k-1]);
                ++swp;
            }
            ++cmp;
        }
    }

    auto end = std::chrono::steady_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}

int getNextGap(int gap){
    gap = (gap*10)/13;
  
    if (gap < 1)
        return 1;
    return gap;
}

void combSort(std::vector<int>& array, std::chrono::nanoseconds& duration){
    int gap = array.size();
    bool swapped = true;
    auto begin = std::chrono::steady_clock::now();
    while(gap!=1 || swapped == true){
        gap = getNextGap(gap);
        swapped = false;
        for(int i=0; i<array.size()-gap; ++i){
            if(array[i]>array[i+gap]){
                std::swap(array[i], array[i+gap]);
                swapped = true;
                ++swp;
            }
            ++cmp;
        }
    }

    auto end = std::chrono::steady_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}

void selectionSort(std::vector<int>& array, std::chrono::nanoseconds& duration){
    auto begin = std::chrono::steady_clock::now();
    for(int step=0; step<array.size()-1; ++step){
        int min_i = step;
        for(int i=step+1; i<array.size(); ++i){
            if(array[i]<array[min_i]){
                min_i = i;
            }
            ++cmp;
        }
        std::swap(array[min_i], array[step]);
        ++swp;
    }

    auto end = std::chrono::steady_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}

void insertionSort(std::vector<int>& array, std::chrono::nanoseconds& duration){
    auto begin = std::chrono::steady_clock::now();
    for(int step=1; step<array.size(); ++step){
        int key = array[step];
        int j=step-1;

        while(key<array[j] && j>=0){
            ++cmp;
            array[j+1] = array[j];
            ++att;
            --j;
        }
        array[j+1] = key;
        ++att;
    }

    auto end = std::chrono::steady_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}

void gnomeSort(std::vector<int>& array, std::chrono::nanoseconds& duration){
    auto begin = std::chrono::steady_clock::now();
    int index = 0;
    while(index<array.size()){
        if(index==0) ++index;
        ++cmp;
        if(array[index]>=array[index-1]){
            ++index;
        }
        else{
            std::swap(array[index], array[index-1]);
            --index;
            ++swp;
        }
    }

    auto end = std::chrono::steady_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}

void shellSort(std::vector<int>& array, std::chrono::nanoseconds& duration){
    auto begin = std::chrono::steady_clock::now();
    for(int gap=array.size()/2; gap>0; gap/=2){
        for(int i = gap; i<array.size(); ++i){
            int temp = array[i];
            ++att;
            int j;
            for(j=i; j>=gap && array[j-gap]>temp; j-=gap){
                array[j] = array[j-gap];
            }
            ++cmp;
            array[j] = temp;
            ++att;
        }
    }

    auto end = std::chrono::steady_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}

int qSPartition(std::vector<int>& array, int left, int right){
    int pivot = array[right];
    int l = left-1;
    att+=2;
    for(int r=left; r<right; ++r){
        ++cmp;
        if(array[r]<pivot){
            ++l;
            std::swap(array[l], array[r]);
            att+=3;
        }
    }
    std::swap(array[l+1], array[right]);
    att+=3;
    return l+1;
}

void quickSort(std::vector<int>& array, int left, int right, std::chrono::nanoseconds& duration){
    auto begin = std::chrono::steady_clock::now();
    
    ++cmp;
    if(left<right){
        int pivotIndex = qSPartition(array, left, right);
        quickSort(array, left, pivotIndex-1, duration);
        quickSort(array, pivotIndex+1, right, duration);
    }

    auto end = std::chrono::steady_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}

struct Node{
    int key;
    struct Node *left, *right;
};

struct Node *newNode(int item){
    struct Node *temp = new Node;
    temp->key=item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void storeSorted(Node *root, std::vector<int>& array, int& i){
    if(root!=NULL){
        storeSorted(root->left, array, i);
        array[i++] = root->key;
        ++att;
        storeSorted(root->right, array, i);
    }
}

Node* insert(Node* node, int key){
    if(node == NULL) return newNode(key);

    ++cmp;
    if(key<node->key){
        node->left = insert(node->left, key);
        ++att;
    }
    else if(key>node->key){
        node->right = insert(node->right, key);
        ++att;
    }

    return node;
}

void treeSort(std::vector<int>& array, std::chrono::nanoseconds& duration){
    auto begin = std::chrono::steady_clock::now();

    struct Node* root = NULL;
    root = insert(root, array[0]);
    for(int i=1; i<array.size(); ++i) root = insert(root, array[i]);

    int i = 0;
    storeSorted(root, array, i);

    auto end = std::chrono::steady_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}

void merge(std::vector<int>& array, int p, int q, int r){
    int n1 = q-p+1, n2 = r-q;

    std::vector<int> L, M;

    for(int i=0; i<n1; ++i){
        L.push_back(array[p+i]);
        ++att;
    }
    for(int j=0; j<n2; ++j){
        M.push_back(array[q+1+j]);
        ++att;
    }

    int i = 0, j = 0, k = p;

    while(i<n1 && j<n2){
        cmp+=2;
        if(L[i]<=M[j]){
            array[k] = L[i];
            ++i;
            ++att;
        }else{
            array[k] = M[j];
            ++j;
            ++att;
        }
        ++k;
    }

    while(i<n1){
        ++cmp;
        array[k] = L[i];
        ++i;
        ++k;
        ++att;
    }

    while(j<n2){
        ++cmp;
        array[k] = M[j];
        ++j;
        ++k;
        ++att;
    }
}

void mergeSort(std::vector<int>& array, int left, int right, std::chrono::nanoseconds& duration){
    auto begin = std::chrono::steady_clock::now();

    ++cmp;
    if(left<right){
        int m = left+(right-left)/2;

        mergeSort(array, left, m, duration);
        mergeSort(array, m+1, right, duration);

        merge(array, left, m, right);
    }

    auto end = std::chrono::steady_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}

void heapSort(std::vector<int>& array, std::chrono::nanoseconds& duration){
    auto begin = std::chrono::steady_clock::now();

    for(int i=array.size()/2-1; i>=0; --i){
        int parent = i, left = 2*parent+1, right = 2*parent+2;
        
        while(left<array.size()){
            int maxChild = left;
            if(right<array.size() && array[right]>array[maxChild]){
                maxChild = right;
            }
            ++cmp;
            if(array[parent] < array[maxChild]){
                std::swap(array[parent], array[maxChild]);
                att+=3;
                parent = maxChild;
                left = 2*parent+1;
                right = 2*parent+2;
            }else{
                break;
            }
            ++cmp;
        }
    }

    for(int i=array.size()-1; i>0; --i){
        std::swap(array[0], array[i]);
        att+=3;

        int parent = 0, left = 2*parent+1, right = 2*parent+2;

        while(left < i){
            int maxChild = left;
            if(right<i && array[right]>array[maxChild]){
                maxChild = right;
            }
            ++cmp;
            if(array[parent] < array[maxChild]){
                std::swap(array[parent], array[maxChild]);
                att+=3;
                parent = maxChild;
                left = 2*parent+1;
                right = 2*parent+2;
            }else{
                break;
            }
            ++cmp;
        }
    }

    auto end = std::chrono::steady_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}

// Neradau paprasto example internete, tai pasinaudojau chatgpt, sorry
void strandSort(std::vector<int>& array, std::chrono::nanoseconds& duration){
    auto begin = std::chrono::steady_clock::now();
    std::vector<int> result;

    while(!array.empty()){
        std::vector<int> sublist{
            array[0]
        };
        array.erase(array.begin());

        for(auto it=array.begin(); it!=array.end();){
            if(*it>=sublist.back()){
                sublist.push_back(*it);
                it = array.erase(it);
            }
            else{
                ++it;
            }
            ++cmp;
        }

        if(result.empty()){
            result = std::move(sublist);
        }else{
            std::vector<int> merged;

            auto it1 = result.begin(), end1 = result.end(), it2 = sublist.begin(), end2 = sublist.end();

            while(it1!=end1 && it2!=end2){
                if(*it1 < *it2){
                    merged.push_back(*it1++);
                }else{
                    merged.push_back(*it2++);
                }
                ++cmp;
            }
            ++cmp;

            merged.insert(merged.end(), it1, end1);
            merged.insert(merged.end(), it2, end2);

            result = std::move(merged);
        }

    }

    array = result;

    auto end = std::chrono::steady_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}