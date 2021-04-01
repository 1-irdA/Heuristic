# bin-packing
FF, FFD, BF, BFD in C++.  

![Alt text](assets/box.png?raw=true "Box")

##  Explanations
FF -> First-Fit  
FFD -> First-Fit Decreasing  
BF -> Best-Fit  
BFD -> Best-Fit Decreasing  

We consider n objects of "sizes" a1, a2, ... an and boxes (in unlimited number) always of the same "size" A.  
It is assumed that for each object i, we have 0 ≤ ai ≤ A.  
The problem is to minimize the number of boxes to be used in order to store the n objects.  
The problem is to minimize the number of boxes to be used in oder to store the n objects.  
There is no known polynomial algorithm to solve this problem.  
The bin packing problem is not in class P; in fact, it is an NP-complete problem.  

## Make

• Compile  

```sh
make main
```

• Run  

```sh
make run
```

## Docker

• Build image  

```sh
docker build -t bin-packing
```

• Run image  

```sh
docker run -it bin-packing
```