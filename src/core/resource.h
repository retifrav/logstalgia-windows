/*
    Copyright (c) 2009 Andrew Caudwell (acaudwell@gmail.com)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. The name of the author may not be used to endorse or promote products
       derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
    IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
    OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
    IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
    NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
    THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <string>
#include <exception>

class ResourceException : public std::exception {
protected:
    std::string resource;
public:
    ResourceException(const std::string& resource) : resource(resource) {}
    virtual ~ResourceException() throw () {};

    virtual const char* what() const throw() { return resource.c_str(); }
};

class Resource {
    int refs;
public:
    std::string resource_name;
    Resource() { refs =0; };
    Resource(const std::string& resource_name) : resource_name(resource_name), refs(0) {};
    virtual ~Resource() {};

    void setResourceName(const std::string& resource_name) {
        if(this->resource_name.empty()) this->resource_name = resource_name;
    };

    int refcount() { return refs; };
    void addref()  { refs++; };
    void deref()   { refs--; };
};

class ResourceManager {

protected:
    std::map<std::string,Resource*> resources;
    std::string resource_dir;
public:

    void setDir(const std::string& resource_dir);
    std::string getDir();

    ResourceManager();
    virtual ~ResourceManager();

    void purge();
    void release(Resource* resource);
};

#endif
