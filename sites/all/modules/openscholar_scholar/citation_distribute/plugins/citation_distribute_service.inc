<?php 

/** 
 * Abstract base class defining a server for citation distribution.  
 */
abstract class citation_distribute_service {
	public $name;
	public $type; //push, file, metadata.  may not be really necessary.
	
	/**
	 * Distributes a node to chosen service(s)
	 */
	abstract public function save();
	
	/**
	 * Copies data from biblio and node data into array labeled for this service
	 */
	abstract public function map_metadata();
	
	/*
	 * Themes data into format appropriate for this service
	 */
	abstract public function render();
}