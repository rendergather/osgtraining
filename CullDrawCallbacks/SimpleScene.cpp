#include "SimpleScene.h"

#include "CullCallback.h"

#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osgDB/ReadFile>

SimpleScene::SimpleScene( osg::Camera *_pCamera )
{
	m_rootNode = new osg::Group;

	//инициализировать геометрию
	InitGeom();

	osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "flt/sphere/sphere.flt" );

	m_rootNode->addChild( model.get() );

	m_rootNode->setCullCallback( new CullCallback( "node callback: " ) );

	m_rootNode->setDataVariance( osg::Object::DYNAMIC );
}

SimpleScene::~SimpleScene()
{

}

void SimpleScene::InitGeom()
{
	//инициализировать геометрию
	osg::Geode* geode = new osg::Geode();

	geode->addDrawable(new osg::ShapeDrawable(new osg::Sphere(osg::Vec3(0.0f,0.0f,0.0f),1.0f)));

//	m_rootNode->addChild( geode );

	// Don't throw away single-vertex primitives.
	osg::BoundingBox bbox( -50, -50, -50, 50, 50, 50);
	geode->setInitialBound( bbox );

}