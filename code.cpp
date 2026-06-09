#include <iostream>
#include <vector>
#include <string>
#include<fstream>
using namespace std;

class DocumentElement{
public:
virtual string render()=0;
};

class TextElement : public DocumentElement{
private:
string text;
public:
TextElement(string text){
    this->text=text;
}
string render() override{
return text;
}
};

class ImageElement: public DocumentElement{
    private:
    string image;
    public:
    ImageElement(string image){
        this->image=image;
    }
    string render()override{
        return image;
    }
};

// making of document

class Document{
    private:
    vector<DocumentElement*>documentelement;
    public:
    void addelement(DocumentElement* element){
        documentelement.push_back(element);
    }

    string render(){
        string result;
        for(auto i:documentelement){
            result += i->render();
        }
        return result;
    }
};

// persistence making

class Persistence{
    public:
    virtual void save(string data)=0;
};

class SavetoFile : public Persistence{
    public:
    void save(string data) override{
        ofstream outFile("document.text");
        if(outFile){
            outFile<< data;
            outFile.close();
            cout<<"document is saved in file";
        }
        else{
            cout<<"there is an error in saving the file ";
        }
    }
};

class SaveToDb : public Persistence {
    public:
    void save(string data) override{
        cout<<"save to db";
    }
};

// document editor making

class DocumentEditor{
    private:
    Document * doc;
    Persistence * storager;
    string renderedDocument;

    public:
    DocumentEditor (Document* doc, Persistence * storager){
        this->doc=doc;
        this->storager=storager;
    }
    void addtext(string text){
        doc->addelement(new TextElement(text));

    }
    void addImage(string image){
        doc->addelement(new ImageElement(image));
    }

     string renderDocument() {
    if(renderedDocument.empty()) {
        renderedDocument = doc->render();
    }
    return renderedDocument;
}

    void saveDocument() {
    storager->save(renderDocument());
}
};

int main() {
    Document* document = new Document();
    Persistence* persistence = new SavetoFile();

    DocumentEditor* editor = new DocumentEditor(document, persistence);

    // Simulate a client using the editor with common text formatting features.
    editor->addtext("Hello, world!");
    //editor->addNewLine();
    editor->addtext("This is a real-world document editor example.");
    //editor->addNewLine();
    //editor->addTabSpace();
    editor->addtext("Indented text after a tab space.");
    //editor->addNewLine();
    editor->addImage("picture.jpg");

    // Render and display the final document.
    cout << editor->renderDocument() << endl;

    editor->saveDocument();

    //delete editor;
    //delete persistence;
    //delete document;

    return 0;
}
