#include "ofApp.h"
#include "cstdlib"
#include "ctime"

//--------------------------------------------------------------
void ofApp::setup(){
	std::srand(std::time(0));
	generateNewCircles();	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < circles.size(); i++) {
		int x = 150 + i * 200;
		int y = 300;
		int rayon = circles[i];

		ofSetColor(0, 0, 255);//cercle bleu
		ofDrawCircle(x, y, rayon);
		ofSetColor(0);//text noir
		ofDrawBitmapString(std::to_string(rayon), x - 10, y + 5);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'r' || key == 'R') {
		circles.clear();
		generateNewCircles();
	}
	if (key == 'b' || key == 'B') {
		triABulles();
	}
	if (key == 'i' || key == 'I') {
		triParInsertion();
	}
	if (key == 'm' || key == 'M') {
		triFusion();
	}
	if (key == 'q' || key == 'Q') {
		triRapide();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::generateNewCircles() {
	for (int i = 0; i < 5; i++) {
		int n = 10 + std::rand() % 91;
		circles.push_back(n);
	}
}
void ofApp::triABulles() {
	for (int i = 0; i < circles.size() - 1; i++) {
		for (int j = 0; j < circles.size() - i - 1; j++) {
			if (circles[j] > circles[j + 1]) {
				std::swap(circles[j], circles[j + 1]);
			}
		}
	}
}
void ofApp::triParInsertion() {
	for (int i = 1; i < circles.size(); i++) {
		int key = circles[i];
		int j = i - 1;

		while (j >= 0 && circles[j] > key) {
			circles[j + 1] = circles[j];
			j--;
		}
		circles[j + 1] = key;
	}
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
	std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
	std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

	int i = 0, j = 0, k = left;
	while (i < leftArr.size() && j < rightArr.size()) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k++] = leftArr[i++];
		}
		else {
			arr[k++] = rightArr[j++];
		}
	}
	while (i < leftArr.size()) arr[k++] = leftArr[i++];
	while (j < rightArr.size()) arr[k++] = rightArr[j++];
}
void mergeSort(std::vector<int>& arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
void ofApp::triFusion() {
	mergeSort(circles, 0, circles.size() - 1);
}

int partition(std::vector<int>& arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return i + 1;
}
void quickSort(std::vector<int>& arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void ofApp::triRapide() {
	quickSort(circles, 0, circles.size() - 1);
}