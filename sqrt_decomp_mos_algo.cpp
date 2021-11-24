// change function as required
int query(int L, int R)
{
	int sum = 0;
	int LB = L / blk;
	int RB = R / blk;
	if (LB == RB)
	{
		for (int i = L; i <= R; i++) {
			sum += ar[i];
		}
	}
	else
	{
		for (int i = L; i < blk * (LB + 1); i++) {
			sum += ar[i];
		}
		for (int i = LB + 1; i < RB; i++) {
			sum += block[i];
		}
		for (int i = blk * RB; i <= R; i++) {
			sum += ar[i];
		}
	}
	return sum;
}



// comparator function
bool comp(query a, query b)
{
	int x = a.l / blk;
	int y = b.l / blk;
	if (x != y)
		return x < y;
	if (x % 2)
		return a.r < b.r;
	else
		return a.r > b.r;
}



// pointer movement
while (currL > L) {
	currL--;
	add(currL);
}
while (currL < L) {
	remove(currL);
	currL++;
}
while (currR > R) {
	remove(currR);
	currR--;
}
while (currR < R) {
	currR++;
	add(currR);
}
