#include <iostream>
#include <fstream>

using namespace std;

int bubbleSort(double myArray[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    double temp = 0;
    for (int j = 0; j < n - 1; ++j)
    {
      if(myArray[j] > myArray[j + 1])
      {
        temp = myArray[j + 1];
        myArray[j + 1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
  return clock();
}

int selectionSort(double arr[], int n)
{
  int i;
  int j;
  int minIndex;
  double temp;

  for (i = 0; i < n - 1; ++i)
  {
    minIndex = i;

    for (j = i + 1; j < n; ++j)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }
    temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
  return clock();
}

int insertionSort(double arr[], int n)
{
  int i;
  int j;
  double temp;
  for (i = 1; i < n; ++i)
  {
    temp = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > temp)
    {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = temp;
  }
  return clock();
}

void swap(double* a, double* b)
{
  double temp = *a;
  *a = *b;
  *b = temp;
}

int partition(double arr[], int start, int end)
{
  double pivot = arr[end];
  int i = start - 1;

  for (int j = start; j <= end - 1; ++j)
  {
    if (arr[j] <= pivot)
    {
      ++i;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[end]);
  return (i + 1);
}

int quickSort(double arr[], int start, int end)
{
  if (start < end)
  {
    double pivot = partition(arr, start, end);

    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
  }
  return clock();
}

int main(int argc, char** argv)
{
  ifstream reader;
  reader.open(argv[1]);
  if (reader.fail())
  {
    cout << "File does not exist." << endl;
    exit(0);
  }

  string temp;
  getline(reader, temp);
  int size = stoi(temp);
  double array1[size];
  double array2[size];
  double array3[size];
  double array4[size];
  for (int i = 0; i < size; ++i)
  {
    getline(reader, temp);
    array1[i] = stod(temp);
    array2[i] = stod(temp);
    array3[i] = stod(temp);
    array4[i] = stod(temp);
  }

  int bubbleTime;
  int selectionTime;
  int insertionTime;
  int quickTime;

  cout << "Bubble Sort" << endl;
  bubbleTime = bubbleSort(array1, size);
  cout << "Time elapsed: " << (double) bubbleTime / (double) CLOCKS_PER_SEC << " seconds" << endl;

  cout << "Selection Sort" << endl;
  selectionTime = selectionSort(array2, size);
  cout << "Time elapsed: " << ((double) selectionTime / (double) CLOCKS_PER_SEC) - ((double) bubbleTime / (double) CLOCKS_PER_SEC) << " seconds" << endl;

  cout << "Insertion Sort" << endl;
  insertionTime = insertionSort(array3, size);
  cout << "Time elapsed: " << ((double) insertionTime / (double) CLOCKS_PER_SEC) - ((double) selectionTime / (double) CLOCKS_PER_SEC) << " seconds" << endl;

  cout << "Quick Sort" << endl;
  quickTime = quickSort(array4, 0, size - 1);
  cout << "Time elapsed: " << ((double) quickTime / (double) CLOCKS_PER_SEC) - ((double) insertionTime / (double) CLOCKS_PER_SEC) << " seconds" << endl;

  return 0;
}
