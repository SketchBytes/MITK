#ifndef BASEDATA_H_HEADER_INCLUDED_C1EBB6FA
#define BASEDATA_H_HEADER_INCLUDED_C1EBB6FA

#include "mitkCommon.h"
#include "Geometry3D.h"
#include "Geometry2D.h"
#include "PropertyList.h"

namespace mitk {

class BaseProcess;

//##ModelId=3D6A0D7D00EC
//##Documentation
//## Base of all data objects, e.g., images, contours, surfaces etc. Inherits
//## from itk::DataObject and thus can be included in a pipeline.
class BaseData : public itk::DataObject
{	
public:
    //##ModelId=3E10262200CE
    typedef Geometry3D::Pointer Geometry3DPointer;

    mitkClassMacro(mitk::BaseData,itk::DataObject)

        //itkNewMacro(Self);  

        //##ModelId=3DCBE2BA0139
        const mitk::Geometry3D& GetGeometry() const;
    //##ModelId=3E3C4ACB0046
    //##Documentation
    //## Return the Geometry2D of the slice (@a s, @a t). The method does not
    //## simply call GetGeometry()->GetGeometry2D(). Before doing this, it
    //## makes sure that the Geometry2D is up-to-date before returning it (by
    //## setting the update extent appropriately and calling
    //## UpdateOutputInformation).
    //## 
    //## @warning GetGeometry2D not yet completely implemented. Appropriate
    //## setting of the update extent is missing.
    virtual mitk::Geometry2D::ConstPointer GetGeometry2D(int s, int t);

    //##ModelId=3E3FE0420273
    mitk::PropertyList::Pointer GetPropertyList();

    virtual void UnRegister() const;

    virtual int GetRealReferenceCount() const;
protected:
    //##ModelId=3E3FE04202B9
    BaseData();
    //##ModelId=3E3FE042031D
    ~BaseData();
    //##ModelId=3E15551A03CE
    Geometry3DPointer m_Geometry3D;
    //##ModelId=3E3FE0420242
    PropertyList::Pointer m_PropertyList;

    mutable itk::SmartPointer<mitk::BaseProcess> m_SmartSourcePointer;
    mutable unsigned int m_SourceOutputIndexDuplicate;
    virtual void ConnectSource(itk::ProcessObject *arg, unsigned int idx) const;
private:
    mutable bool m_Unregistering;
    mutable bool m_CalculatingRealReferenceCount;
    mutable int m_RealReferenceCount;

    friend class mitk::BaseProcess;
};

} // namespace mitk



#endif /* BASEDATA_H_HEADER_INCLUDED_C1EBB6FA */
