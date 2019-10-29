/*
Student Name:Yiğit Can
Student Number:Özkaya
Project Number: 2
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include "RestaurantOrganizer.h"

using namespace std;

RestaurantOrganizer::RestaurantOrganizer(const vector<int>& tableCapacityInput){
    numberOfTables = tableCapacityInput.size();
    for(int i=0;i<numberOfTables;i++){
        tableCapacity[i] = tableCapacityInput[i];
        heap[i] = i;
        heapUp(i);
    }
}

void RestaurantOrganizer::addNewGroup(int groupSize, ofstream& outFile){
    // IMPLEMENT ME!
    if(groupSize>tableCapacity[heap[0]]){
        outFile << "-1" <<endl;
    }
    else{
        outFile<<heap[0]<<endl;
        tableCapacity[heap[0]]-=groupSize;
        heapDown(0);
    }
}

void RestaurantOrganizer::heapUp(int index){
    // IMPLEMENT ME
    int parent=(index-1)/2;
    for(;index>=1&&tableCapacity[heap[index]]>=tableCapacity[heap[(index-1)/2]];index=(index-1)/2){
        parent=(index-1)/2;
        if(tableCapacity[heap[index]]==tableCapacity[heap[parent]]){
            if(heap[index]>heap[parent]){
                break;
            }
        }
        int x=heap[index];
        heap[index]=heap[parent];
        heap[parent]=x;
    }


}

void RestaurantOrganizer::heapDown(int index){
    // IMPLEMENT ME!

    while(index<numberOfTables&&2*index+1<numberOfTables){
        if(2*index+2<numberOfTables){
           if(tableCapacity[heap[2*index+1]]<tableCapacity[heap[2*index+2]]){
               if(tableCapacity[heap[index]]<tableCapacity[heap[2*index+2]]){
                int l=heap[index];
                heap[index]=heap[2*index+2];
                heap[2*index+2]=l;
                index=2*index+2;
                continue;
               }
               else if(tableCapacity[heap[index]]==tableCapacity[heap[2*index+2]]){
                   if(heap[index]<heap[2*index+2]){
                       break;
                   }
                   else{
                       int l=heap[index];
                       heap[index]=heap[2*index+2];
                       heap[2*index+2]=l;
                       index=2*index+2;
                       continue;
                   }
               }
               else{
                   break;
               }
           }
           else if(tableCapacity[heap[2*index+1]]>tableCapacity[heap[2*index+2]]){
               if(tableCapacity[heap[2*index+1]]>tableCapacity[heap[index]]){
                   int l=heap[index];
                   heap[index]=heap[2*index+1];
                   heap[2*index+1]=l;
                   index=2*index+1;
                   continue;
               }
               else if(tableCapacity[heap[2*index+1]]==tableCapacity[heap[index]]){
                   if(heap[2*index+1]>heap[index]){
                       break;
                   }
                   else{
                       int l=heap[index];
                       heap[index]=heap[2*index+1];
                       heap[2*index+1]=l;
                       index=2*index+1;
                       continue;
                   }
               }
               else{
                   break;
               }
           }
           else{
               if(tableCapacity[heap[index]]<tableCapacity[heap[2*index+1]]){
                   if(heap[2*index+1]>heap[2*index+2]){
                       int l=heap[index];
                       heap[index]=heap[2*index+2];
                       heap[2*index+2]=l;
                       index=2*index+2;
                       continue;
                   }
                   else{
                       int l=heap[index];
                       heap[index]=heap[2*index+1];
                       heap[2*index+1]=l;
                       index=2*index+1;
                       continue;
                   }
               }
               else if(tableCapacity[heap[index]]==tableCapacity[heap[2*index+1]]){
                   if(heap[index]<heap[2*index+1]&&heap[index]<heap[2*index+2]){
                       break;
                   }
                   else{
                       if(heap[index]<heap[2*index+1]&&heap[index]>heap[2*index+2]){
                           int l=heap[index];
                           heap[index]=heap[2*index+2];
                           heap[2*index+2]=l;
                           index=2*index+2;
                           continue;
                       }
                       else{
                           int l=heap[index];
                           heap[index]=heap[2*index+1];
                           heap[2*index+1]=l;
                           index=2*index+1;
                           continue;
                       }
                   }
               }
               else{
                   break;
               }
           }
        }
        else{
            if(tableCapacity[heap[2*index+1]]>tableCapacity[heap[index]]){
                int l=heap[index];
                heap[index]=heap[2*index+1];
                heap[2*index+1]=l;
                index=2*index+1;
                continue;
            }
            else if(tableCapacity[heap[2*index+1]]==tableCapacity[heap[index]]){
                if(heap[2*index+1]<heap[index]){
                    int l=heap[index];
                    heap[index]=heap[2*index+1];
                    heap[2*index+1]=l;
                    index=2*index+1;
                    continue;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
    }

}

void RestaurantOrganizer::printSorted(ofstream& outFile){
    // IMPLEMENT ME!
    int fake=numberOfTables;
    for (int number=0;number<fake;number++) {
        outFile<<tableCapacity[heap[0]];
        tableCapacity[heap[0]]=-7;
        heapDown(0);
        outFile<<" ";
    }
}

// YOU CAN ADD YOUR HELPER FUNCTIONS

