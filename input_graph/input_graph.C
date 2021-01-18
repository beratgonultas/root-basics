void input_graph()

{

	double x[5] = {1,2,3,4,5};
	double y[5] = {1,4,9,16,25};

	TGraph *gr = new TGraph(5, x, y);

	gr->SetMarkerStyle(2);
	gr->SetMarkerSize(2);
	gr->SetMarkerColor(2);
	gr->GetXaxis()->SetTitle("X Axis");
	gr->GetYaxis()->SetTitle("Y Axis");
	
	TCanvas *c1 = new TCanvas();
	gr->Draw("AP");

}
