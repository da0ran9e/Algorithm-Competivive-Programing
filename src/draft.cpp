void replace_all(
    std::string& s,
    std::string const& toReplace,
    std::string const& replaceWith
) {
    std::string buf;
    std::size_t pos = 0;
    std::size_t prevPos;

    // Reserves rough estimate of final size of string.
    buf.reserve(s.size());

    while (true) {
        prevPos = pos;
        pos = s.find(toReplace, pos);
        if (pos == std::string::npos)
            break;
        buf.append(s, prevPos, pos - prevPos);
        buf += replaceWith;
        pos += toReplace.size();
    }

    buf.append(s, prevPos, s.size() - prevPos);
    s.swap(buf);
}
//////////////////////////////////////////////////////////

void giaithua(int n );

int main(){

       int n;
       printf("Nhap so can tinh giai thua: "); scanf("%d",&n);
       printf("Ket qua la: ");
       giaithua(n);
}

void giaithua(int n){

      int A[500000],i,j,m=1;
      long long r=0,q;
      A[0]=1;
      for(i=2;i<=n;i++){
      for(j=0;j<m;j++){
           q=r;
           r=(A[j]*i+r)/10;
          A[j]=(A[j]*i+q)%10;
   }
     while(r>0){
          A[m]=r%10;
          m++;
          r=r/10;
   }
 }
        for(i=m-1;i>=0;i--)  printf("%d",A[i]);
}
////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
 
// Function to display the array
void display(int a[], int n)
{
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
 
// Function to find the permutations
void findPermutations(int a[], int n)
{
 
  // Sort the given array
  sort(a, a + n);
 
  // Find all possible permutations
  cout << "Possible permutations are:\n";
  do {
    display(a, n);
  } while (next_permutation(a, a + n));
}
 
// Driver code
int main()
{
 
  int a[] = { 10, 20, 30, 40 };
 
  int n = sizeof(a) / sizeof(a[0]);
 
  findPermutations(a, n);
 
  return 0;
}