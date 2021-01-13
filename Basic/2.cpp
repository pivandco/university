int main() {
	//int in_seconds = 4000;
	int in_seconds = 90400;

	int seconds = in_seconds % 60;
	int minutes = in_seconds / 60 % 60;
	int hours = in_seconds / 3600 % 24;
	int days = in_seconds / 3600 / 24;

	return 0;
}