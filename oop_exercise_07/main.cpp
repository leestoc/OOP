#include <iostream>
#include <iomanip>

#include "document.hpp"

int main() {

    uint32_t option;

    std::cout
        << "Help:\n0. Create new document\n1. Insert figure: <figure-type> <coord-center> <coord0>\n2. Delete figure: <index>\n"
        << "3. Save document: <document-name>\n4. Load document: <document-name>\n5. Undo last operation\n6. Redo last undone operation\n"
        << "7. Print Document"
        << std::endl;

    Document doc;
    while (std::cin >> option) {
        /// New Document
        if (option == 0) {
            doc.Create();
        }
        /// Insert Figure
        else if (option == 1) {
            std::string figureType;
            std::cin >> figureType;
            std::unique_ptr<Figure> obj = Factory<Figure>::GetInstance().Create(figureType);
            std::cin >> *(obj.get());
            doc.Add(std::move(obj));
            std::cout << "Inserted!" << std::endl;
        }
        /// Delete Figure
        else if (option == 2) {
            uint32_t index;
            std::cin >> index;
            doc.Remove(index);
            std::cout << "Removed!" << std::endl;
        }
        /// Save Document
        else if (option == 3) {
            std::string filename;
            std::cin >> filename;
            doc.Save(filename);
            std::cout << "Saved!" << std::endl;
        }
        /// Load Document
        else if (option == 4) {
            std::string filename;
            std::cin >> filename;
            doc.Load(filename);
            std::cout << "Loaded!" << std::endl;
        }
        /// Undo Operation
        else if (option == 5) {
            doc.Undo();
            std::cout << "Undone!" << std::endl;
        }
        /// Redo Operation
        else if (option == 6) {
            doc.Redo();
            std::cout << "Redone!" << std::endl;
        }
        /// Print Figures
        else if (option == 7) {
            doc.Print();
        }
        /// Default
        else {
            std::cout << "No such option :)" << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;
    return 0;
}