#ifndef VECTOR_H

#define VECTOR_H

class B_IDataFile;

class B_Vector
{
public:
        double x;
        double y;
        double z;
};

extern B_IDataFile& operator >>(B_IDataFile& file, B_Vector &vector);

#endif /* VECTOR_H */