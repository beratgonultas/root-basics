void rand_hist()
{
	TRandom2 *rand = new TRandom2(1);
	TH1F *hist = new TH1F("hist", "Random Number Histogram", 100, 0, 100);
	
	for(int i = 0; i < 100000; i++)
	{
		double r = rand->Rndm()*100;
		cout << r << endl;
		hist->Fill(r);
	} 
	
	TCanvas *c1 = new TCanvas();
	hist->GetYaxis()->SetRangeUser(0,10000);
	hist->Draw();


}
