/*
 *  Copyright (C) 2016  The BoxedWine Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __KFMMAP_H__
#define __KFMMAP_H__

#ifndef BOXEDWINE_64BIT_MMU

#include "soft_page.h"

class FilePage : public Page {
protected:
    FilePage(const BoxedPtr<MappedFile>& mapped, U32 index, U32 flags) : Page(File_Page, flags), mapped(mapped), index(index) {}

public:
    static FilePage* alloc(const BoxedPtr<MappedFile>& mapped, U32 index, U32 flags);

    U8 readb(U32 address);
    void writeb(U32 address, U8 value);
    U16 readw(U32 address);
    void writew(U32 address, U16 value);
    U32 readd(U32 address);
    void writed(U32 address, U32 value);
    U8* physicalAddress(U32 address);
    bool inRam() {return false;}
    void close() {delete this;}

    void ondemmandFile(U32 address);

     BoxedPtr<MappedFile> mapped;
     U32 index;
};

#endif

#endif