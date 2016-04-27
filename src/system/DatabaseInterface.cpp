/**
 *  DatabaseInterface.cpp
 *
 *  Version: 1.0.0.0
 *  Created on: 21/04/2016
 *  Modified on: *********
 *  Authors: Adriano Henrique Rossette Leite (adrianohrl@unifei.edu.br)
 *           Christiano Henrique Rezende (c.h.rezende@hotmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include "unifei/expertinos/mrta_vc/system/DatabaseInterface.h"

/**
 *
 */
unifei::expertinos::mrta_vc::system::DatabaseInterface::DatabaseInterface() 
{	
}

/**
 *
 */
unifei::expertinos::mrta_vc::system::DatabaseInterface::~DatabaseInterface() 
{
}

/**
 *
 */
unifei::expertinos::mrta_vc::agents::VoiceCommander unifei::expertinos::mrta_vc::system::DatabaseInterface::getVoiceCommander(int id) 
{
	std::string name = "";
	std::string login_name = "";
	int hierarchy_level = 0;
	unifei::expertinos::mrta_vc::agents::Computer computer(0, "");
	// realizar consultas no DB para preencher o objeto a partir do seu id e enviá-lo
	if (id == 4) 
	{
		login_name = "adrianohrl";
		name = "Adriano Henrique Rossette Leite";
		hierarchy_level = 3;
		computer = unifei::expertinos::mrta_vc::system::DatabaseInterface::getComputer("adrianohrl-pc");
	} 
	else if (id == 5) 
	{
		login_name = "christiano";
		name = "Christiano Henrique Rezende";
		hierarchy_level = 6;
		computer = unifei::expertinos::mrta_vc::system::DatabaseInterface::getComputer("christiano-pc");
	}
	else if (id == 6) 
	{
		login_name = "luis";
		name = "Luís Victor Pessiqueli Bonin";
		hierarchy_level = 6;
		computer = unifei::expertinos::mrta_vc::system::DatabaseInterface::getComputer("luis-pc");
	}
	else if (id == 7) 
	{
		login_name = "heverton";
		name = "Héverton Soares";
		hierarchy_level = 5;
		computer = unifei::expertinos::mrta_vc::system::DatabaseInterface::getComputer("heverton-pc");
	}
	else if (id == 9) 
	{
		login_name = "audeliano";
		name = "Audeliano";
		hierarchy_level = 2;
		computer = unifei::expertinos::mrta_vc::system::DatabaseInterface::getComputer("audeliano-pc");
	}
	return unifei::expertinos::mrta_vc::agents::VoiceCommander(id, name, unifei::expertinos::mrta_vc::agents::HierarchyLevels::toEnumerated(hierarchy_level), login_name, computer);
}

/**
 *
 */
unifei::expertinos::mrta_vc::agents::VoiceCommander unifei::expertinos::mrta_vc::system::DatabaseInterface::getVoiceCommander(std::string login_name) 
{
	int id = 0;
	std::string name = "";
	int hierarchy_level = 0;
	unifei::expertinos::mrta_vc::agents::Computer computer(0, "");
	// realizar consultas no DB para preencher o objeto a partir do seu login_name e enviá-lo
	// Simulado, por enquanto
	if (login_name == "adrianohrl") 
	{
		id = 4;
		name = "Adriano Henrique Rossette Leite";
		hierarchy_level = 3;
		computer = unifei::expertinos::mrta_vc::system::DatabaseInterface::getComputer("adrianohrl-pc");
	} 
	else if (login_name == "christiano") 
	{
		id = 5;
		name = "Christiano Henrique Rezende";
		hierarchy_level = 6;
		computer = unifei::expertinos::mrta_vc::system::DatabaseInterface::getComputer("christiano-pc");
	}
	else if (login_name == "luis") 
	{
		id = 6;
		name = "Luís Victor Pessiqueli Bonin";
		hierarchy_level = 6;
		computer = unifei::expertinos::mrta_vc::system::DatabaseInterface::getComputer("luis-pc");
	}
	else if (login_name == "heverton") 
	{
		id = 7;
		name = "Héverton Soares";
		hierarchy_level = 5;
		computer = unifei::expertinos::mrta_vc::system::DatabaseInterface::getComputer("heverton-pc");
	}
	else if (login_name == "audeliano") 
	{
		id = 9;
		name = "Audeliano Li";
		hierarchy_level = 2;
		computer = unifei::expertinos::mrta_vc::system::DatabaseInterface::getComputer("audeliano-pc");
	}
	return unifei::expertinos::mrta_vc::agents::VoiceCommander(id, name, unifei::expertinos::mrta_vc::agents::HierarchyLevels::toEnumerated(hierarchy_level), login_name, computer);
}

/**
 *
 */
unifei::expertinos::mrta_vc::agents::Computer unifei::expertinos::mrta_vc::system::DatabaseInterface::getComputer(int id) 
{
	std::string hostname = "";
	bool mobile = false;
	double x = 0.0;
	double y = 0.0;
	double theta = 0.0;
	// realizar consultas no DB para preencher o objeto a partir do seu id e enviá-lo
	return unifei::expertinos::mrta_vc::agents::Computer(id, hostname, mobile, x, y, theta);
}

/**
 *
 */
unifei::expertinos::mrta_vc::agents::Computer unifei::expertinos::mrta_vc::system::DatabaseInterface::getComputer(std::string hostname) 
{
	// realizar consultas no DB para preencher o objeto a partir do seu hostname e enviá-lo
	// Simulado, por enquanto
	int id = 0;
	bool mobile = false;
	double x = 0.0;
	double y = 0.0;
	double theta = 0.0;
	if (hostname == "adrianohrl-pc") 
	{
		id = 1;
		x = -1.0;
		y = .5;
		theta = -2.5;
	} 
	else if (hostname == "christiano-pc") 
	{
		id = 2;
	}
	else if (hostname == "luis-pc") 
	{
		id = 3;
		mobile = true;
		x = .6;
		y = -6.4;
		theta = -7.3;
	}
	else if (hostname == "heverton-pc") 
	{
		id = 8;
		x = 1.68;
		y = 6.45;
		theta = -.3;
	}
	else if (hostname == "audeliano-pc") 
	{
		id = 10;
		x = -1.68;
		y = -6.45;
		theta = -.3;
	}
	return unifei::expertinos::mrta_vc::agents::Computer(id, hostname, mobile, x, y, theta);
}
