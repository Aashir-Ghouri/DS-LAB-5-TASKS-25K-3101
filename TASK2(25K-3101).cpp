#include <iostream> //25K-3101
#include <string>
using namespace std;

class TextEditor {
public:
    string undoStack[100];
    string redoStack[100];
    int undoTop = -1;
    int redoTop = -1;

    void type(string word) {
        undoTop++;
        undoStack[undoTop] = word;
        redoTop = -1;
    }

    void undo() {
        if (undoTop >= 0) {
            redoTop++;
            redoStack[redoTop] = undoStack[undoTop];
            undoTop--;
        }
    }

    void redo() {
        if (redoTop >= 0) {
            undoTop++;
            undoStack[undoTop] = redoStack[redoTop];
            redoTop--;
        }
    }

    void print() {
        for (int i = 0; i <= undoTop; i++) {
            cout << undoStack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    TextEditor editor;

    editor.type("Hello");
    editor.print();

    editor.type("World");
    editor.print();

    editor.undo();
    editor.print();

    editor.redo();
    editor.print();

    editor.undo();
    editor.print();

    editor.type("There");
    editor.print();

    editor.redo();
    editor.print();

    return 0;
}
