#ifndef _GEOMETRY_TEXTURE_PATCH_4_H_
#define _GEOMETRY_TEXTURE_PATCH_4_H_

#include <osg/Geometry>
#include <osg/Image>

#include <vector>

class GeometryTexturePatch4
{
public:
	//x,y - �������� ������, sizeC - ���������� ���������, scaleC - ������ ������
	GeometryTexturePatch4( int x , int y , int sizeC , int scaleC , osg::ref_ptr<osg::Image> image , double fAdd , double dScale );

	~GeometryTexturePatch4();

	osg::ref_ptr< osg::Geometry > GetGeometry(){ return m_patchGeom.get(); };
private:
	//������� ������ ������
	osg::ref_ptr<osg::Vec3Array> CreateVertexArray( int x , int y , int sizeC , int scaleC );

	//������� ������ ���������� ���������
	osg::ref_ptr<osg::Vec2Array> CreateTexCoordArray( int x , int y , int sizeC , int scaleC , unsigned char *dataR );

	//��������� ������ ���������
	void FillIndexVector( std::vector< unsigned int > &_vIndex , int sizeC );

	//��������� ������
	osg::ref_ptr< osg::Geometry > m_patchGeom;

	//����� � ���������������
	double m_dAdd;
	double m_dScale;
};

#endif	//_GEOMETRY_TEXTURE_PATCH_4_H_