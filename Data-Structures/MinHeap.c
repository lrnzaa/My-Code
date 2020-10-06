#include <stdio.h>

int arrHeap[100] = {0};
int nElement = 0; //number of element

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void upHeap(int index)
{
	//jika index == index root maka proses selesai
	if(index == 1) return;
	
	int parentIndex = index/2;
	
	//lakukan upheap sampai parent lebih kecil (min heap) atau sampai root
	//cek apakah nilai dari index lebih kecil dari parentnya
	if(arrHeap[index] < arrHeap[parentIndex])
	{
		//tukar datanya
		swap(&arrHeap[index], &arrHeap[parentIndex]);		
		//lanjutkan upheap
		upHeap(parentIndex);
	}
}

void downHeap(int index)
{
	int toIndex = index;
	
	//anak kiri
	int aKi = 2 * index, aKa = 2 * index + 1;
	
	if(aKi <= nElement && arrHeap[toIndex] > arrHeap[aKi])
	{
		toIndex = aKi;
	}
	//anak kanan
	if(aKa <= nElement && arrHeap[toIndex] > arrHeap[aKa])
	{
		toIndex = aKa;
	}
	
	if(toIndex == index) return; //berarti datanya cuma 1
	
	swap(&arrHeap[index], &arrHeap[toIndex]);
	
	downHeap(toIndex);
}

void insertHeap(int insertedKey)
{
	nElement++;
	arrHeap[nElement] = insertedKey;
	upHeap(nElement);
}

int extractMin()
{
	//jika tidak ada data
	if(nElement == 0)
	{
		printf("Heap masih kosong\n");
		//kembalikan nilai 0 jika tidak boleh insert 0, -1 jika 0 diperbolehkan
		return 0;
	}
	
	//jika datanya cuma 1
	if(nElement == 1)
	{
		nElement--;
		return arrHeap[1]; //kembalikan nilai rootnya
	}
	
	//jumlah data lebih dari 1
	//nilai min simpan dulu
	int returnValue = arrHeap[1];
	
	swap(&arrHeap[1], &arrHeap[nElement]); // boleh arrHeap[1] = arrHeap[nElement]
	nElement--;
	downHeap(1);
	
	return returnValue;
}

void printHeap()
{
	int i;
	
	for(i = 1; i <= nElement; i++)
	{
		printf("%d", i);
		
		i == nElement ? printf("\n") : printf (" => ");
	}
	
	for(i = 1; i <= nElement; i++)
	{
		printf("%d", arrHeap[i]);
		
		i == nElement ? printf("\n") : printf (" => ");
	}
}

int main ()
{
	insertHeap(50);
	insertHeap(30);
	insertHeap(90);
	insertHeap(20);
	insertHeap(10);
	insertHeap(15);
	insertHeap(8);
	insertHeap(27);
	insertHeap(19);
	insertHeap(31);
	insertHeap(67);
	insertHeap(93);
	insertHeap(34);
	insertHeap(5);
	insertHeap(35);
	insertHeap(7);
	
	printHeap();
	puts("");
	
	//extract balikin nilai baru dihapus lalu di push
	
	//extracMin digunakan untuk menghasilkan data min dari min heap
	//kemudian menghapusnya
	extractMin();
	
	printHeap();
	
	return 0;
}
