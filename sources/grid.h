//#
//# FILE: grid.h -- Interface to grid-solve module
//#
//# $Id$
//#

#ifndef GRID_H
#define GRID_H

#include "mixed.h"
#include "gstatus.h"

class GridParams   {
	public:
		double minLam, maxLam, delLam, delp1, delp2, tol1,tol2;
		int multi_grid;
		int powLam, trace;
		gOutput *tracefile, *pxifile;
		gStatus &status;

		GridParams(gStatus & = gstatus);
};

class GridSolveModule  {
	private:
		const Nfg<double> &N;
		const NFSupport &S;
		const GridParams &params;
		gArray<int> num_strats;
		MixedProfile<double> P_calc;
		gVector<double> tmp; // scratch
		double lam;
		int static_player;

		gVector<double> UpdateFunc(const MixedProfile<double> &P,int pl,double lam);
		bool CheckEqu(MixedProfile<double> P,double lam,int cur_grid);
		void OutputHeader(gOutput &out);
		void OutputResult(gOutput &out,const MixedProfile<double> P,double lam,double obj_func);
	protected:
		// could use norms other then the simple one
		virtual double Distance(const gVector<double> &a,const gVector<double> &b) const;
	public:
		GridSolveModule(const Nfg<double> &, const GridParams &, const NFSupport &);
		virtual ~GridSolveModule();
		void GridSolve(void);
};

#endif    // GRID_H
