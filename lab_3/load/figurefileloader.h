#ifndef FIGUREFILELOADER_H
#define FIGUREFILELOADER_H

#include "loader.h"
#include "figurebuilder.h"

using namespace std;

class FigureFileLoader : public BaseSourceLoader
{
public:
    FigureFileLoader();
    FigureFileLoader(const shared_ptr<ifstream> &_stream);

    virtual void open(const string &file_name) override;
    virtual void close() override;

    virtual std::shared_ptr<Object> load() override;
};

#endif // FIGUREFILELOADER_H
