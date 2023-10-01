#include <iostream>
#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T>{

   	private:
	    T *arr;
	    int max;
	    int n;
	    static const int MINSIZE;
	    void resize(int new_size){
	    	T arr2[new_size];
		for(int i=0;i<new_size;i++){
		  arr2[i]=arr[i];
		}
		delete arr;
		arr -> arr2;
		max=new_size;
	    }
	public:
	     void insert(int pos,T e){
	    	if(e>0 && e<size){
		   arr[pos]=e;
		}else{
		   std::cout <<"fuera de rango"<<std::endl;
		}
	    }
	    
	     void append(T e){
	    	arr[max]=e;	
	    }

	      void prepend(T e){

		arr[0]=e;
            }

	      T remove(int pos){
	     	if(pos>0 && pos<size-1){
		   return arr[pos];
		   delete[] arr[pos];
		}else{
		   std::cout <<"fuera de rango"<<std::endl;
		}
	     }

	      T get(int pos){
	     	 if(pos>0 && pos<size-1){
                   return arr[pos];
                }else{
                   std::cout <<"fuera de rango"<<std::endl;
                }
             }

	      int search(T e){
	      	for(int i=0; i<size;i++){
		  if(arr[i]=e){
		    return i;
		  }
		
		return -1;
	      }
	      }

	      bool empty(){
	      	for(int i=0;i<size;i++){
		  if(arr[i]=!nullptr){
		    return false;
		    break;
		  }
		    return true;
		}
	      }

	      int size(){
	      	for(int i=0;i<size;i++){
		  if(i=nullptr){
		    return i;
		  }
		}
	      }
	     

	    ListArray(){
		if(MINSIZE!=2){
		   throw std::invalid_argument("Está mal");
		}

		*arr= new T(MINSIZE);

	   	for(int i=0;i<MINSIZE;i++)
		  *arr[i]=nullptr;
	    }
	    
	    ~ListArray(){
	    	delete[] arr;
	    }
	    
	    T operator[](int pos){
	    	if(pos>0 && pos<size-1){
                   return arr[pos];
                }else{
                   throw std::out_of_range ("fuera de rango");
                }
	    }

	    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
	    	out << ListArray();
		return out;
	    }	    

	   
	      
	    
};
