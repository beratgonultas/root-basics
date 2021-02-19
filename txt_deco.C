void txt_deco()
{
	TH1F *hist1 = new TH1F("hist1", "Histogram", 100, 1, 10);
	
	fstream file;
	file.open("data_gaus.txt", ios::in);
	

	double value;	

	while(1)
	{
		file>>value;
		hist1->Fill(value);
		if(file.eof()) break;	
	}

	file.close();

	hist1->GetXaxis()->SetTitle("X Axis");
	hist1->GetYaxis()->SetTitle("Y Axis");

	TF1 *fit = new TF1("fit", "gaus", 4, 6);

	TCanvas *c1 = new TCanvas();
	hist1->Draw();
	hist1->Fit("fit", "R");

	TLegend *leg = new TLegend(0.7, 0.7, 0.9, 0.9);
	leg->AddEntry(hist1, "Measured Data", "L");
	leg->AddEntry(fit, "Fit Function", "L");
	leg->Draw();
	

	TLine *l = new TLine(1, 20, 10, 20);
	l->SetLineWidth(2);
	l->SetLineColor(kOrange);
	l->Draw();

	double x0 = 6.3;
	int bin = hist1->FindBin(x0);
	double y0 = hist1->GetBinContent(bin);

	TArrow *arrow = new TArrow(7, 25, x0, y0);
	arrow->SetLineWidth(2);
	arrow->SetArrowSize(0.02);
	arrow->SetLineColor(kBlue);
	arrow->Draw();

	TLatex *t = new TLatex(7, 25, "Important point");
	t->Draw();
	
	

}
