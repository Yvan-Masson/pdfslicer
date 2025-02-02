// PDF Slicer
// Copyright (C) 2018 Julián Unrrein

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef PAGERENDERER_HPP
#define PAGERENDERER_HPP

#include "page.hpp"

namespace Slicer {

class PageRenderer {
public:
    PageRenderer(const Glib::RefPtr<const Page>& page);

    Glib::RefPtr<Gdk::Pixbuf> render(int targetSize) const;

private:
    struct RenderDimensions {
        Page::Size outputSize;
        double scale;
        poppler::rotation_enum rotation;
    };

    const Glib::RefPtr<const Page>& m_page;

    static constexpr double standardDpi = 72.0;
    RenderDimensions getRenderDimensions(int targetSize) const;
};

} // namespace Slicer

#endif // PAGERENDERER_HPP
