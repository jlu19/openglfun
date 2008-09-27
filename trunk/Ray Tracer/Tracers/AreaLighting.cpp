/*
 *  AreaLighting.cpp
 *  Ray Tracer
 *
 *  Created by NoEvilPeople on 9/26/08.
 *  Copyright 2008 jmc2385@rit.edu. All rights reserved.
 *
 */

#include "AreaLighting.h"
#include "World.h"
#include "Material.h"

// -------------------------------------------------------------------- default constructor

AreaLighting::AreaLighting(void)
: Tracer()
{}


// -------------------------------------------------------------------- constructor

AreaLighting::AreaLighting(World* _worldPtr)
: Tracer(_worldPtr)
{}


// -------------------------------------------------------------------- destructor

AreaLighting::~AreaLighting(void) {}


// -------------------------------------------------------------------- trace_ray

MyRGBColor	
AreaLighting::trace_ray(const Ray& ray) const {
	ShadeRec sr(world_ptr->hit_objects(ray)); // sr is copy constructed
	
	if (sr.hit_an_object)   {
		sr.ray = ray;
		return (sr.material_ptr->area_light_shade(sr));   
	}
	else
		return (world_ptr->background_color);
}

// --------------------------------------- DEPTH NOT USED YET 

MyRGBColor	
AreaLighting::trace_ray(const Ray ray, const int depth) const {
	ShadeRec sr(world_ptr->hit_objects(ray)); // sr is copy constructed
	
	if (sr.hit_an_object)   {
		sr.ray = ray;
		return (sr.material_ptr->area_light_shade(sr));   
	}
	else
		return (world_ptr->background_color);
}

