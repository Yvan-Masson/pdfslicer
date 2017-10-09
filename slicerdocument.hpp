#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <gdkmm/pixbuf.h>
#include <poppler.h>
#include <string>
#include <vector>

namespace Slicer {

class Document {
public:
    // Constructor and destructor
    Document(std::string filePath);
    ~Document();

    // Interface
    Glib::RefPtr<Gdk::Pixbuf> renderPage(int pageNumber,
                                         int width,
                                         int height);

    // Member element access
    const std::vector<PopplerPage*>& pages() const { return m_pages; };

private:
    // Member objects
    PopplerDocument* m_popplerDocument;
    std::vector<PopplerPage*> m_pages;
};
}

#endif // DOCUMENT_HPP
