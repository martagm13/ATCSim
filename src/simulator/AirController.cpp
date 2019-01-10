/*
 * AirController.cpp
 *
 *  Created on: 21/07/2014
 *      Author: paco
 *
 *  Copyright 2014 Francisco Martín
 *
 *  This file is part of ATCSim.
 *
 *  ATCSim is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ATCSim is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with ATCSim.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "AirController.h"
#include "Airport.h"
#include "Flight.h"
#include "Position.h"
#include <list>

namespace atcsim{

	/*
	 * AirController.cpp
	 *
	 *  Created on: 21/07/2014
	 *      Author: paco
	 *
	 *  Copyright 2014 Francisco Martín
	 *
	 *  This file is part of ATCSim.
	 *
	 *  ATCSim is free software: you can redistribute it and/or modify
	 *  it under the terms of the GNU General Public License as published by
	 *  the Free Software Foundation, either version 3 of the License, or
	 *  (at your option) any later version.
	 *
	 *  ATCSim is distributed in the hope that it will be useful,
	 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
	 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	 *  GNU General Public License for more details.
	 *
	 *  You should have received a copy of the GNU General Public License
	 *  along with ATCSim.  If not, see <http://www.gnu.org/licenses/>.
	 */

	#include "AirController.h"
	#include "Airport.h"
	#include "Flight.h"
	#include "Position.h"
	#include <list>

	AirController::AirController()
	{
	    // TODO Auto-generated constructor stub
	}

	AirController::~AirController()
	{
	    // TODO Auto-generated destructor stub
	}

	void
	AirController::doWork()
	{
	    std::list<Flight*> flights = Airport::getInstance()->getFlights();
	    std::list<Flight*>::iterator it;
		std::list<Flight*>::iterator it2;

	    //Ruta aterrizaje final
	    Position pos_aterrizaje_1(1700.0, 0.0, 50.0);
	    Position pos_aterrizaje_2(200.0, 0.0, 25.0);
	    Position pos_aterrizaje_3(-750.0, 0.0, 25.0);

	    Route ra1, ra2, ra3;

	    ra1.pos = pos_aterrizaje_1;
	    ra1.speed = 150.0;
	    ra2.pos = pos_aterrizaje_2;
	    ra2.speed = 50.0;
	    ra3.pos = pos_aterrizaje_3;
	    ra3.speed = 19.0;

	    //Ruta aproximación y positivas, cuadrante abajo
	    Position pos_aterrizaje_0diag(5000.0, 4500, 200.0);
	    Position pos_aterrizaje_1diag(4000.0, 1500, 100.0);
	    Position pos_aterrizaje_2diag(3000.0, 500, 100.0);

	    Route  ra0diag, ra1diag, ra2diag;

	    ra0diag.pos = pos_aterrizaje_0diag;
	    ra0diag.speed = 250.0;
	    ra1diag.pos = pos_aterrizaje_1diag;
	    ra1diag.speed = 200.0;
	    ra2diag.pos = pos_aterrizaje_2diag;
	    ra2diag.speed = 200.0;

	    //Ruta aproximación y negativas, cuadrante abajo
	    Position pos_aterrizaje_3diag(5000.0, -4500, 200.0);
	    Position pos_aterrizaje_4diag(4000.0, -1500.0, 100.0);
	    Position pos_aterrizaje_5diag(3000.0, -500.0, 100.0);

	    Route ra3diag,ra4diag,ra5diag;

	    ra3diag.pos = pos_aterrizaje_3diag;
	    ra3diag.speed = 250.0;
	    ra4diag.pos = pos_aterrizaje_4diag;
	    ra4diag.speed = 200.0;
	    ra5diag.pos = pos_aterrizaje_5diag;
	    ra5diag.speed = 200.0;

	    //Ruta aproximación y positivas, cuadrante arriba
	    Position pos_aterrizaje_0diag2(5000.0, 300, 500.0);
	    Position pos_aterrizaje_1diag2(4000.0, 100, 200.0);
	    Position pos_aterrizaje_2diag2(3000.0, 50.0, 100.0);

	    Route  ra0diag2, ra1diag2, ra2diag2;

	    ra0diag2.pos = pos_aterrizaje_0diag2;
	    ra0diag2.speed = 250.0;
	    ra1diag2.pos = pos_aterrizaje_1diag2;
	    ra1diag2.speed = 200.0;
	    ra2diag2.pos = pos_aterrizaje_2diag2;
	    ra2diag2.speed = 200.0;

	    //Ruta aproximación y negativas, cuadrante arriba
	    Position pos_aterrizaje_3diag2(5000.0, -300, 500.0);
	    Position pos_aterrizaje_4diag2(4000.0, -100.0, 200.0);
	    Position pos_aterrizaje_5diag2(3000.0, -50.0, 100.0);

	    Route  ra3diag2, ra4diag2, ra5diag2;

	    ra3diag2.pos = pos_aterrizaje_3diag2;
	    ra3diag2.speed = 250.0;
	    ra4diag2.pos = pos_aterrizaje_4diag2;
	    ra4diag2.speed = 200.0;
	    ra5diag2.pos = pos_aterrizaje_5diag2;
	    ra5diag2.speed = 200.0;

	    //Ruta aproximación extra
	    Position recta1(9000.0, 0, 2000.0);
	    Position recta2(6000.0, 0, 1000.0);
	    Position recta3(4000.0, 0, 300.0);

	    Route  rec1, rec2, rec3;

	    rec1.pos = recta1;
	    rec1.speed = 150.0;
	    rec2.pos = recta2;
	    rec2.speed = 200.0;
	    rec3.pos = recta3;
	    rec3.speed = 200.0;

		Position recta1baj(9000.0, 0, 200.0);
	    Position recta2baj(6000.0, 0, 200.0);
	    Position recta3baj(4000.0, 0, 200.0);

		Route  rec1baj, rec2baj, rec3baj;

		rec1baj.pos = recta1baj;
		rec1baj.speed = 250.0;
		rec2baj.pos = recta2baj;
		rec2baj.speed = 200.0;
		rec3baj.pos = recta3baj;
		rec3baj.speed = 200.0;

	    //Ruta espera y positivas, cuadrante abajo
	    Position pos_c1(7000.0, 15000, 2000.0);
	    Position pos_c2(7000.0, 2000, 2000.0);
	    Position pos_c3(1000.0, 2000, 2000.0);
	    Position pos_c4(1000.0, 15000, 2000.0);
	    Position pos_c5(7000.0, 15000, 2500.0);
	    Position pos_c6(7000.0, 2000, 3000.0);
	    Position pos_c7(1000.0, 2000, 3000.0);
	    Position pos_c8(1000.0, 15000, 3000.0);
	    Position pos_c9(7000.0, 15000, 3500.0);
	    Position pos_c10(7000.0, 2000, 4000.0);
	    Position pos_c11(1000.0, 2000, 4000.0);
	    Position pos_c12bis(1000.0, 15000, 4000.0);

	    Route  c1, c2, c3, c4,c5,c6,c7,c8,c9,c10,c11,c12bis;

	    c1.pos = pos_c1;
	    c1.speed = 200.0;
	    c2.pos = pos_c2;
	    c2.speed = 200.0;
	    c3.pos = pos_c3;
	    c3.speed = 200.0;
	    c4.pos = pos_c4;
	    c4.speed = 200.0;
	    c5.pos = pos_c5;
	    c5.speed = 200.0;
	    c6.pos = pos_c6;
	    c6.speed = 200.0;
	    c7.pos = pos_c7;
	    c7.speed = 200.0;
	    c8.pos = pos_c8;
	    c8.speed = 200.0;
	    c9.pos = pos_c9;
	    c9.speed = 200.0;
	    c10.pos = pos_c10;
	    c10.speed = 200.0;
	    c11.pos = pos_c11;
	    c11.speed = 200.0;
	    c12bis.pos = pos_c12bis;
	    c12bis.speed = 200.0;

	    //Ruta espera y positivas, cuadrante arriba
	    Position pos_c12(17000.0, 15000, 2500.0);
	    Position pos_c22(17000.0, 2000, 2500.0);
	    Position pos_c32(11000.0, 2000, 2500.0);
	    Position pos_c42(11000.0, 15000, 2500.0);
	    Position pos_c52(17000.0, 15000, 1400.0);
	    Position pos_c62(17000.0, 2000, 1400.0);
	    Position pos_c72(11000.0, 2000, 1400.0);
	    Position pos_c82(11000.0, 15000, 1400.0);
	    Position pos_c92(17000.0, 15000, 300.0);
	    Position pos_c102(17000.0, 2000, 300.0);
	    Position pos_c112(11000.0, 2000, 300.0);
	    Position pos_c122(11000.0, 15000, 300.0);

	    Route c42, c12, c22, c32,c52,c62,c72,c82,c92,c102,c112,c122;

	    c12.pos = pos_c12;
	    c12.speed = 200.0;
	    c22.pos = pos_c22;
	    c22.speed = 200.0;
	    c32.pos = pos_c32;
	    c32.speed = 200.0;
	    c42.pos = pos_c42;
	    c42.speed = 200.0;
	    c52.pos = pos_c52;
	    c52.speed = 200.0;
	    c62.pos = pos_c62;
	    c62.speed = 200.0;
	    c72.pos = pos_c72;
	    c72.speed = 200.0;
	    c82.pos = pos_c82;
	    c82.speed = 200.0;
	    c92.pos = pos_c92;
	    c92.speed = 200.0;
	    c102.pos = pos_c102;
	    c102.speed = 200.0;
	    c112.pos = pos_c112;
	    c112.speed = 200.0;
	    c122.pos = pos_c122;
	    c122.speed = 200.0;

	    //Ruta espera y negativas, cuadrante abajo
	    Position pos_c1neg(7000.0, -15000, 2000.0);
	    Position pos_c2neg(7000.0, -2000, 2000.0);
	    Position pos_c3neg(1000.0, -2000, 2000.0);
	    Position pos_c4neg(1000.0, -15000, 2000.0);
	    Position pos_c5neg(7000.0, -15000, 2500.0);
	    Position pos_c6neg(7000.0, -2000, 3000.0);
	    Position pos_c7neg(1000.0, -2000, 3000.0);
	    Position pos_c8neg(1000.0, -15000, 3000.0);
	    Position pos_c9neg(7000.0, -15000, 3500.0);
	    Position pos_c10neg(7000.0, -2000, 4000.0);
	    Position pos_c11neg(1000.0, -2000, 4000.0);
	    Position pos_c12neg(1000.0, -15000, 4000.0);

	    Route c4neg, c1neg, c2neg, c3neg,c5neg,c6neg,c7neg,c8neg,c9neg,c10neg,c11neg,c12neg;

	    c1neg.pos = pos_c1neg;
	    c1neg.speed = 200.0;
	    c2neg.pos = pos_c2neg;
	    c2neg.speed = 200.0;
	    c3neg.pos = pos_c3neg;
	    c3neg.speed = 200.0;
	    c4neg.pos = pos_c4neg;
	    c4neg.speed = 200.0;
	    c5neg.pos = pos_c5neg;
	    c5neg.speed = 200.0;
	    c6neg.pos = pos_c6neg;
	    c6neg.speed = 200.0;
	    c7neg.pos = pos_c7neg;
	    c7neg.speed = 200.0;
	    c8neg.pos = pos_c8neg;
	    c8neg.speed = 200.0;
	    c9neg.pos = pos_c9neg;
	    c9neg.speed = 200.0;
	    c10neg.pos = pos_c10neg;
	    c10neg.speed = 200.0;
	    c11neg.pos = pos_c11neg;
	    c11neg.speed = 200.0;
	    c12neg.pos = pos_c12neg;
	    c12neg.speed = 200.0;

	    //Ruta espera y negativas, cuadrante arriba
	    Position pos_c1neg2(17000.0, -15000, 2500.0);
	    Position pos_c2neg2(17000.0, -2000, 2500.0);
	    Position pos_c3neg2(11000.0, -2000, 2500.0);
	    Position pos_c4neg2(11000.0, -15000, 2500.0);
	    Position pos_c5neg2(17000.0, -15000, 1400.0);
	    Position pos_c6neg2(17000.0, -2000, 1400.0);
	    Position pos_c7neg2(11000.0, -2000, 1400.0);
	    Position pos_c8neg2(11000.0, -15000, 1400.0);
	    Position pos_c9neg2(17000.0, -15000, 300.0);
	    Position pos_c10neg2(17000.0, -2000, 300.0);
	    Position pos_c11neg2(11000.0, -2000, 300.0);
	    Position pos_c12neg2(11000.0, -15000, 300.0);


	    Route c4neg2, c1neg2, c2neg2, c3neg2,c5neg2,c6neg2,c7neg2,c8neg2,c9neg2,c10neg2,c11neg2,c12neg2;

	    c1neg2.pos = pos_c1neg2;
	    c1neg2.speed = 200.0;
	    c2neg2.pos = pos_c2neg2;
	    c2neg2.speed = 200.0;
	    c3neg2.pos = pos_c3neg2;
	    c3neg2.speed = 200.0;
	    c4neg2.pos = pos_c4neg2;
	    c4neg2.speed = 200.0;
	    c5neg2.pos = pos_c5neg2;
	    c5neg2.speed = 200.0;
	    c6neg2.pos = pos_c6neg2;
	    c6neg2.speed = 200.0;
	    c7neg2.pos = pos_c7neg2;
	    c7neg2.speed = 200.0;
	    c8neg2.pos = pos_c8neg2;
	    c8neg2.speed = 200.0;
	    c9neg2.pos = pos_c9neg2;
	    c9neg2.speed = 200.0;
	    c10neg2.pos = pos_c10neg2;
	    c10neg2.speed = 200.0;
	    c11neg2.pos = pos_c11neg2;
	    c11neg2.speed = 200.0;
	    c12neg2.pos = pos_c12neg2;
	    c12neg2.speed = 200.0;

		//Ruta espera y negativas, cuadrante arriba
		Position pos_c1neg3(-1000.0, -15000, 2000.0);
	    Position pos_c2neg3(-7000.0, -2000, 2000.0);
	    Position pos_c3neg3(-7000.0, -2000, 2000.0);
	    Position pos_c4neg3(-1000.0, -15000, 2000.0);
	    Position pos_c5neg3(-1000.0, -15000, 2500.0);
	    Position pos_c6neg3(-7000.0, -2000, 3000.0);
	    Position pos_c7neg3(-7000.0, -2000, 3000.0);
	    Position pos_c8neg3(-1000.0, -15000, 3000.0);
	    Position pos_c9neg3(-1000.0, -15000, 3500.0);
	    Position pos_c10neg3(-7000.0, -2000, 4000.0);
	    Position pos_c11neg3(-7000.0, -2000, 4000.0);
	    Position pos_c12neg3(-1000.0, -15000, 4000.0);


	    Route c4neg3, c1neg3, c2neg3, c3neg3,c5neg3,c6neg3,c7neg3,c8neg3,c9neg3,c10neg3,c11neg3,c12neg3;

	    c1neg3.pos = pos_c1neg2;
	    c1neg3.speed = 200.0;
	    c2neg3.pos = pos_c2neg2;
	    c2neg3.speed = 200.0;
	    c3neg3.pos = pos_c3neg2;
	    c3neg3.speed = 200.0;
	    c4neg3.pos = pos_c4neg2;
	    c4neg3.speed = 200.0;
	    c5neg3.pos = pos_c5neg2;
	    c5neg3.speed = 200.0;
	    c6neg3.pos = pos_c6neg2;
	    c6neg3.speed = 200.0;
	    c7neg3.pos = pos_c7neg2;
	    c7neg3.speed = 200.0;
	    c8neg3.pos = pos_c8neg2;
	    c8neg3.speed = 200.0;
	    c9neg3.pos = pos_c9neg2;
	    c9neg3.speed = 200.0;
	    c10neg3.pos = pos_c10neg2;
	    c10neg3.speed = 200.0;
	    c11neg3.pos = pos_c11neg2;
	    c11neg3.speed = 200.0;
	    c12neg3.pos = pos_c12neg2;
	    c12neg3.speed = 200.0;

	    if (!Airport::getInstance()->is_booked_landing())
	    {
	        Flight* primero = *(flights.begin());

	        primero -> getRoute()->clear();
	    }

	    for(it = flights.begin(); it!=flights.end(); ++it)
	    {
	    	if((*it)->getRoute()->empty())
	        {
	        	if (Airport::getInstance()->is_booked_landing())
	            {
	            	if ((*it)->getPosition().get_y() <= 0 && (*it)->getPosition().get_x() > 10000 )
	                {
	                	if((*it)->getPosition().get_x()>=14000)
	                    {
	                    	if((*it)->getPosition().get_y()<=-6500)
	                        {
	                             (*it)->getRoute()->push_back(c2neg2);
	                             (*it)->getRoute()->push_back(c3neg2);
	                        }
	                             (*it)->getRoute()->push_back(c3neg2);
	                    }

	                    if((*it)->getPosition().get_x()<=14000)
	                    {
	                         if((*it)->getPosition().get_y()<= -6500)
	                         {
	                              (*it)->getRoute()->push_back(c1neg2);
	                              (*it)->getRoute()->push_back(c2neg2);
	                              (*it)->getRoute()->push_back(c3neg2);
	                         }
	                    }

	                         (*it)->getRoute()->push_back(c4neg2);
	                         (*it)->getRoute()->push_back(c5neg2);
	                         (*it)->getRoute()->push_back(c6neg2);
	                         (*it)->getRoute()->push_back(c7neg2);
	                         (*it)->getRoute()->push_back(c8neg2);
	                         (*it)->getRoute()->push_back(c9neg2);
	                         (*it)->getRoute()->push_back(c10neg2);
	                         (*it)->getRoute()->push_back(c11neg2);
	                         (*it)->getRoute()->push_back(c12neg2);

	                    }

	                    if ((*it)->getPosition().get_y() >= 0 && (*it)->getPosition().get_x() <= 10000)
	                    {
	                         if((*it)->getPosition().get_x()>=4000)
	                         {
	                              if((*it)->getPosition().get_y()>=6500)
	                              {
	                              		(*it)->getRoute()->push_back(c2);
	                                    (*it)->getRoute()->push_back(c3);
	                              }
	                              (*it)->getRoute()->push_back(c3);
	                         }

	                         if((*it)->getPosition().get_x()<=4000)
	                         {
	                              if((*it)->getPosition().get_y()>6500)
	                              {
	                                  (*it)->getRoute()->push_back(c1);
	                                  (*it)->getRoute()->push_back(c2);
	                                  (*it)->getRoute()->push_back(c3);
	                               }
	                          }

	                          (*it)->getRoute()->push_back(c4);
	                          (*it)->getRoute()->push_back(c5);
	                          (*it)->getRoute()->push_back(c6);
	                          (*it)->getRoute()->push_back(c7);
	                          (*it)->getRoute()->push_back(c8);
	                          (*it)->getRoute()->push_back(c9);
	                          (*it)->getRoute()->push_back(c10);
	                          (*it)->getRoute()->push_back(c11);
	                          (*it)->getRoute()->push_back(c12bis);
	                      }

	                        if ((*it)->getPosition().get_y() >= 0 && (*it)->getPosition().get_x() > 10000)
	                        {
	                            if((*it)->getPosition().get_x()>=14000)
	                            {
	                                if((*it)->getPosition().get_y()>=6500)
	                                {
	                                    (*it)->getRoute()->push_back(c22);
	                                    (*it)->getRoute()->push_back(c32);
	                                }
	                                (*it)->getRoute()->push_back(c32);
	                            }

	                            if((*it)->getPosition().get_x()<=14000)
	                            {
	                                if((*it)->getPosition().get_y()>=6500)
	                                {
	                                    (*it)->getRoute()->push_back(c12);
	                                    (*it)->getRoute()->push_back(c22);
	                                    (*it)->getRoute()->push_back(c32);
	                                }
	                            }

	                            (*it)->getRoute()->push_back(c42);
	                            (*it)->getRoute()->push_back(c52);
	                            (*it)->getRoute()->push_back(c62);
	                            (*it)->getRoute()->push_back(c72);
	                            (*it)->getRoute()->push_back(c82);
	                            (*it)->getRoute()->push_back(c92);
	                            (*it)->getRoute()->push_back(c102);
	                            (*it)->getRoute()->push_back(c112);
	                            (*it)->getRoute()->push_back(c122);
	                        }

	                        if ((*it)->getPosition().get_y() <= 0 && (*it)->getPosition().get_x() <= 10000)
	                        {
	                            if((*it)->getPosition().get_x()>=4000)
	                            {
	                                if((*it)->getPosition().get_y()<=-6500)
	                                {
	                                    (*it)->getRoute()->push_back(c2neg);
	                                    (*it)->getRoute()->push_back(c3neg);
	                                }
	                                (*it)->getRoute()->push_back(c3neg);
	                            }

	                            if((*it)->getPosition().get_x()<=4000)
	                            {
	                                if((*it)->getPosition().get_y()<= -6500)
	                                {
	                                    (*it)->getRoute()->push_back(c1neg);
	                                    (*it)->getRoute()->push_back(c2neg);
	                                    (*it)->getRoute()->push_back(c3neg);
	                                }
	                            }

	                            (*it)->getRoute()->push_back(c4neg);
	                            (*it)->getRoute()->push_back(c5neg);
	                            (*it)->getRoute()->push_back(c6neg);
	                            (*it)->getRoute()->push_back(c7neg);
	                            (*it)->getRoute()->push_back(c8neg);
	                            (*it)->getRoute()->push_back(c9neg);
	                            (*it)->getRoute()->push_back(c10neg);
	                            (*it)->getRoute()->push_back(c11neg);
	                            (*it)->getRoute()->push_back(c12neg);
	                        }

							it2 = flights.begin();

							if(flights.size()>1)
							{
								 if((*it2)->getPosition().get_y() <= 4000.0 && (*it2)->getPosition().get_y() >= -4000.0 && (*it2)->getPosition().get_x() <= 4000.0)
								 {
								 it2++;
								 (*it2) -> getRoute()->clear();
								 (*it2)->getRoute()->push_back(rec1baj);
								 (*it2)->getRoute()->push_back(rec2baj);
								 (*it2)->getRoute()->push_back(rec3baj);
								 (*it2)->getRoute()->push_back(ra1);
								 (*it2)->getRoute()->push_back(ra2);
								 (*it2)->getRoute()->push_back(ra3);
							 	}
						 	}
	                    }
	                    else if((*it)->getPoints() > 25)
	                    {
	                    	Airport::getInstance()->book_landing();

	                       	if ((*it)->getPosition().get_y() < -10000.0 && (*it)->getPosition().get_x() < 12000.0)
	                        {
	                             (*it)->getRoute()->push_back(ra3diag);
	                             (*it)->getRoute()->push_back(ra4diag);
	                             (*it)->getRoute()->push_back(ra5diag);
	                        }

	                        if ((*it)->getPosition().get_y() >= 10000.0 && (*it)->getPosition().get_x() < 12000.0)
	                        {
	                             (*it)->getRoute()->push_back(ra0diag);
	                             (*it)->getRoute()->push_back(ra1diag);
	                             (*it)->getRoute()->push_back(ra2diag);
	                        }

	                        if ((*it)->getPosition().get_y() <= 0.0 && (*it)->getPosition().get_x() > 12000.0)
	                        {
	                              (*it)->getRoute()->push_back(ra3diag2);
	                              (*it)->getRoute()->push_back(ra4diag2);
	                              (*it)->getRoute()->push_back(ra5diag2);
	                        }

	                        if ((*it)->getPosition().get_y() > 0.0 && (*it)->getPosition().get_x() > 12000.0)
	                        {
	                              (*it)->getRoute()->push_back(ra0diag2);
	                              (*it)->getRoute()->push_back(ra1diag2);
	                              (*it)->getRoute()->push_back(ra2diag2);
	                       	}

	                        (*it)->getRoute()->push_back(ra1);
	                        (*it)->getRoute()->push_back(ra2);
	                        (*it)->getRoute()->push_back(ra3);
						}
	              }
	       }
	}
};  // namespace atcsim
