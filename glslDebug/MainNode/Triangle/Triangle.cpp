#include "Triangle.h"

#include <osg/Geometry>
#include <osg/Image>
#include <osgDB/ReadFile>
#include <osgDB/FileUtils>
#include <osg/Texture2D>

Triangle::Triangle()
{

}

Triangle::~Triangle()
{

}

void Triangle::Init()
{
	//������������� ������� ���������
	m_Node = new osg::MatrixTransform;

	osg::Matrix mT;
	mT.setTrans( 0,1,0);
	m_Node->setMatrix( mT );

	//������� ���������
	m_Node->addChild( CreateGeode().get() );	
}

osg::ref_ptr< osg::Geode > Triangle::CreateGeode()
{
	//������� ���������
	osg::ref_ptr< osg::Geode > mGeode = new osg::Geode;

	osg::ref_ptr< osg::Geometry > geom = new osg::Geometry;

	//�� ������������ ���������� ������ �.�. ����� �������
	geom->setUseDisplayList( false );

	// Create an array of four vertices.
	osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array;
	geom->setVertexArray( v.get() );

	v->push_back( osg::Vec3( -3 , 3 , -3 ) );
	v->push_back( osg::Vec3( 3 , 3 , -3 ) );
	v->push_back( osg::Vec3( 0 , 3 , 3 ) );

	// Create an array for the single normal.
	osg::ref_ptr< osg::Vec3Array > n = new osg::Vec3Array;
	geom->setNormalArray( n.get() );
	geom->setNormalBinding( osg::Geometry::BIND_OVERALL );
	n->push_back( osg::Vec3( 0.f, -1.f, 0.f ) );


	// Create an array for the single normal.
	osg::ref_ptr< osg::Vec3Array > c = new osg::Vec3Array;
	geom->setColorArray( c.get() );
	geom->setColorBinding( osg::Geometry::BIND_PER_VERTEX );
	c->push_back( osg::Vec3( 1.f, 0.f, 0.f ) );
	c->push_back( osg::Vec3( 1.f, 1.f, 0.f ) );
	c->push_back( osg::Vec3( 0.f, 0.f, 1.f ) );

	geom->addPrimitiveSet( new osg::DrawArrays( osg::PrimitiveSet::TRIANGLES , 0, v->size() ) );

	mGeode->addDrawable( geom.get() );

	return mGeode.get();
}